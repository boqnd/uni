#include "interface.h"
#include "queue.cpp"
#include <vector>

/// NOTE: Worker is used only for busy workers, free workers are stored just as a number
struct Worker {
  int time; ///< The time at which worker departs
  ResourceType product;

  Worker(int time, ResourceType product) : time(time), product(product) {}
};

/// NOTE: Pair is used for Clients, to store the index number of every client
template<typename T, typename P>
struct Pair {
    T data1;
    P data2;

    Pair(T data1_, P data2_) : data1(data1_), data2(data2_) {}
};

/// NOTE: Storage is used to store the quantity of bananas and schweppes at one place;
struct Storage {
  int bananaQuantity;
  int schweppesQuantity;

	Storage(int banana, int schweppes) : bananaQuantity(banana), schweppesQuantity(schweppes) {}
};

struct MyStore : Store {
	ActionHandler *actionHandler = nullptr; ///< action handler
	size_t freeWorkers; ///< the number of available workers
	queue<Worker> busyWorkers; ///< busy workers in queue, will come back in the same order they were sent (60 minutes after leaving)
	queue< Pair<Client, int> > customers; ///< clients in queue, will be processed in order
	std::vector< Pair<Client, int> > customers_toLeave; ///< processed customers, which are whaiting for worker to come back
	Storage* storage; ///< available quantity of banana and schweppes
	/// NOTE: expected storage is used to determine if a worker need to leave based on client's order and incomming storage
	Storage* expectedStorage; ///< quantity of banana and schweppes which will be stocked by busy workers
	/// NOTE: number of clients is used for correct indexing of the clients
	int numberOfClients; ///< the number of clients for the day

	void setActionHandler(ActionHandler *handler) override {
		actionHandler = handler;
	}

	void init(int workerCount, int startBanana, int startSchweppes) override {
		this->freeWorkers = workerCount;
		this->storage = new Storage(startBanana, startSchweppes);
		this->expectedStorage = new Storage(0, 0);
		numberOfClients = 0;
	}

	void addClients(const Client *clients, int count) override {		
		for (size_t i = 0; i < count; i++) {
			this->customers.push(Pair<Client, int>(clients[i], this->numberOfClients++));
		}
	}

	/// @param minute current time
	void advanceTo(int minute) override {		
		while(!this->customers.empty() || !this->customers_toLeave.empty()) {
			Client* current = &this->customers.front().data1; /// Customer to be processed next

			if (!this->customers.empty() && !checkIfCustomerWillLeaveBefore(current->arriveMinute)) {
				/// Customers in the queue to be processed and no whaiting customers will leave before next client in the queue

				if (!checkStorage(current->banana, current->schweppes)) {
					/// Insufficient storage quantity for current customer

					if (checkIfWorkerWillBeDoneBefore(current->arriveMinute)) {
						/// A worker will be back before current customer arrives at the store

						int _time = this->busyWorkers.front().time + 60; /// The time at which a worker will be back

						if (_time > minute) {
							/// The worker will be back after the current time
							break;
						}
						freeWorker(current->arriveMinute);
						while (checkIfLongestWhaitingCustomerCanLeave()) {
							/// Longest whaiting customer can leave with the whanted quantity of products

							customerLeave(this->customers_toLeave.front().data2, _time, this->customers_toLeave.front().data1.banana, this->customers_toLeave.front().data1.schweppes);
							this->customers_toLeave.erase(this->customers_toLeave.begin());
						}
					} else {
						/// No worker will be back before this customer arrives at the store

						if (current->arriveMinute > minute) {
							/// The client to be processed will arrive at the store after the current time
							break;
						}

						sendWorkersIfNeeded(current);
						
						addCustomerToWhaiting(this->customers.front());

						this->customers.pop();
					}
				} else {
					/// Current customer can leave with wanted quantity of products

					if (current->arriveMinute > minute) {
						/// The client to be processed will arrive at the store after the current time
						break;
					}

					customerLeave(this->customers.front().data2, current->arriveMinute, current->banana, current->schweppes);

					this->customers.pop();
				}
			} else {
				/// Customer will leave before the next client arrives at the store

				Client *customerToLeave = &this->customers_toLeave.back().data1; /// Leaving customer

				if (checkIfWorkerWillBeDoneBefore(customerToLeave->arriveMinute + customerToLeave->maxWaitTime)) {
					// A worker will be back before customer leave

					int _time = this->busyWorkers.front().time + 60;
					if (_time > minute) {
						/// The worker will be back after the current time
						break;
					}

					freeWorker(customerToLeave->arriveMinute + customerToLeave->maxWaitTime);

					while(checkIfLongestWhaitingCustomerCanLeave()) {
						/// Longest whaiting customer can leave with the whanted quantity of products

						customerLeave(this->customers_toLeave.front().data2, _time, this->customers_toLeave.front().data1.banana, this->customers_toLeave.front().data1.schweppes);
						this->customers_toLeave.erase(this->customers_toLeave.begin());
					}
				} else {
					// Customer leave because cant whait more

					if (customerToLeave->arriveMinute + customerToLeave->maxWaitTime > minute) {
						/// The client will leave the store after the current time
						break;
					}

					customerLeave(this->customers_toLeave.back().data2, customerToLeave->arriveMinute + customerToLeave->maxWaitTime, (customerToLeave->banana <= storage->bananaQuantity ? customerToLeave->banana : storage->bananaQuantity), (customerToLeave->schweppes <= storage->schweppesQuantity ? customerToLeave->schweppes : storage->schweppesQuantity));

					this->customers_toLeave.pop_back();
				}
			}
		}

		while (!this->busyWorkers.empty()) {
			/// Worker is comming back after all the customers left

			if (this->busyWorkers.front().time + 60 > minute) {
				/// Worker will be back after the current time
				break;
			}

			freeWorker(this->busyWorkers.front().time + 60);
		}
	}

	virtual int getBanana() const override {
		return this->storage->bananaQuantity;
	}

	virtual int getSchweppes() const override {
		return this->storage->schweppesQuantity;
	}

	/// Sending worker to stock product
	/// @param time the minute worker leave
	/// @param product the product to be stocked
	void sendWorker(int time, ResourceType product) {
		if (this->freeWorkers) {
			this->freeWorkers--;
			this->busyWorkers.push(Worker(time, product));

			this->actionHandler->onWorkerSend(this->busyWorkers.back().time,this->busyWorkers.back().product);

			switch (product)
			{
				case ResourceType::banana:
					this->expectedStorage->bananaQuantity += 100;
					break;
				case ResourceType::schweppes:
					this->expectedStorage->schweppesQuantity += 100;
					break;
				default:
					break;
			}
		}
	}

	/// Stock the product worker brought back before @time
	/// @param time the minute worker should be back before
	void freeWorker(int time) {
		if (this->busyWorkers.front().time+60 <= time) {
			switch (this->busyWorkers.front().product) {
				case ResourceType::banana:
					this->storage->bananaQuantity += 100;
					this->expectedStorage->bananaQuantity -= 100;
					break;
				case ResourceType::schweppes:
					this->storage->schweppesQuantity += 100;
					this->expectedStorage->schweppesQuantity -= 100;
					break;
				default:
					break;
			}

			this->actionHandler->onWorkerBack(this->busyWorkers.front().time+60,this->busyWorkers.front().product);

			this->busyWorkers.pop();
			this->freeWorkers++;
		} 
	}

	/// Check if client will leave before @time
	/// @param time the minute client should leave before
	bool checkIfCustomerWillLeaveBefore(int time) {
		if (this->customers_toLeave.empty()) {
			return false;
		}

		return (this->customers_toLeave.back().data1.arriveMinute + this->customers_toLeave.back().data1.maxWaitTime <= time);
	}

	/// Check if storage quantity of bananas and schweppes is sufficient
	/// @param bananas the number of banana wanted
	/// @param schweppes the number of schweppes wanted
	bool checkStorage(int bananas, int schweppes) {
		return (this->storage->bananaQuantity >= bananas && this->storage->schweppesQuantity >= schweppes);
	}

	/// Check if worker will be back before @time
	/// @param time the minute worker should be back before
	bool checkIfWorkerWillBeDoneBefore(int time) {
		if (this->busyWorkers.empty()) {
			return false;
		}
		return (this->busyWorkers.front().time + 60 < time);
	}

	/// Sending worker if storage quantity + expected storage quantity is insufficient
	/// @param current the client to be processed
	void sendWorkersIfNeeded(Client* current) {
		int neededBananas = current->banana - (this->storage->bananaQuantity + this->expectedStorage->bananaQuantity);
		int neededSchweppes = current->schweppes - (this->storage->schweppesQuantity + this->expectedStorage->schweppesQuantity);

		while (this->freeWorkers > 0 && (neededSchweppes > 0 || neededBananas > 0))
		{
			if (neededBananas >= neededSchweppes && neededBananas > 0) {
				
				sendWorker(current->arriveMinute, ResourceType::banana);
				
				neededBananas -= 100;
			} else if (neededSchweppes >= neededBananas && neededSchweppes > 0) {
				
				sendWorker(current->arriveMinute, ResourceType::schweppes);
				
				neededSchweppes -= 100;
			}
		}
	}

	/// Move @client from queue to whaiting
	/// @param client the pair client-id to be moved from the queue to whaiting
	void addCustomerToWhaiting(Pair<Client,int> client) {
		this->customers_toLeave.push_back(client);
	}

	/// Delete customer and substract @bananas and @schweppes from storage
	/// @param idNumber client index number
	/// @param time the client leave time
	/// @param bananas banana quantity
	/// @param schweppes schweppes quantity
	void customerLeave(int idNumber, int time, int bananas, int schweppes) {
		this->storage->bananaQuantity -= bananas;
		this->storage->schweppesQuantity -= schweppes;

		this->actionHandler->onClientDepart(idNumber, time, bananas, schweppes);
	}

	/// Check if the longest whaiting customer's wanted quantity is sufficient in the storage
	bool checkIfLongestWhaitingCustomerCanLeave() {
		if (this->customers_toLeave.empty()) {
			return false;
		}
		return checkStorage(this->customers_toLeave.front().data1.banana, this->customers_toLeave.front().data1.schweppes);
	}
};

Store *createStore() {
	return new MyStore();
}

struct ConsoleHandler : ActionHandler {
	void onWorkerSend(int minute, ResourceType resource) {
    std::cout << "W " << minute << " ";
    switch (resource) {
      case ResourceType::banana: 
        std::cout << "banana" << std::endl;
        break;
      case ResourceType::schweppes:
        std::cout << "schweppes" << std::endl;
        break;
      default:
        break;
    }
  }

	void onWorkerBack(int minute, ResourceType resource) {
    std::cout << "D " << minute << " ";
    switch (resource) {
      case ResourceType::banana: 
        std::cout << "banana" << std::endl;
        break;
      case ResourceType::schweppes:
        std::cout << "schweppes" << std::endl;
        break;
      default:
        break;
    }
  }

	void onClientDepart(int index, int minute, int banana, int schweppes) {
    std::cout << index << " " << minute << " " << banana << " " << schweppes << std::endl;
  }
};

/// The function to be called to start console app
void startConsoleAppStore() {
  Store* store = createStore();
  ConsoleHandler* handler = new ConsoleHandler();

  int nWorkers, nCustomers;
  std::cin >> nWorkers >> nCustomers;

  store->setActionHandler(handler);
  store->init(nWorkers, 0, 0);

  Client* customers = new Client[nCustomers];

  for (size_t i = 0; i < nCustomers; i++)
  {
    int t, b, s, w;
    std::cin >> t >> b >> s >> w;
    Client current{t,b,s,w};
    customers[i] = current;
  }

  store->addClients(customers, nCustomers);
  store->advanceTo(INT_MAX);
}