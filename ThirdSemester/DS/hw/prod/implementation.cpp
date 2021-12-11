#include "interface.h"
#include "queue.cpp"
// #include <queue>
#include <vector>

struct Worker {
  int time;
  ResourceType product;

  Worker(int time, ResourceType product) : time(time), product(product) {}
};

template<typename T, typename P>
struct Pair {
    T data1;
    P data2;

    Pair(T data1_, P data2_) : data1(data1_), data2(data2_) {}
};

struct Storage {
  int bananaQuantity;
  int schweppesQuantity;

  Storage() : bananaQuantity(0), schweppesQuantity(0) {}
	Storage(int banana, int schweppes) : bananaQuantity(banana), schweppesQuantity(schweppes) {}
};

/// This is sample empty implementation you can place your solution here or delete this and include tests to your solution

struct MyStore : Store {
	ActionHandler *actionHandler = nullptr;
	size_t freeWorkers;
	queue<Worker> busyWorkers;
	queue< Pair<Client, int> > customers;
	std::vector< Pair<Client, int> > customers_toLeave;
	Storage* storage;
	Storage* expectedStorage;
	int nextClientId;

	void setActionHandler(ActionHandler *handler) override {
		actionHandler = handler;
	}

	void init(int workerCount, int startBanana, int startSchweppes) override {
		this->freeWorkers = workerCount;
		this->storage = new Storage(startBanana, startSchweppes);
		this->expectedStorage = new Storage(0, 0);
		nextClientId = 0;
	}

	void addClients(const Client *clients, int count) override {		
		for (size_t i = 0; i < count; i++) {
			this->customers.push(Pair<Client, int>(clients[i], this->nextClientId++));
		}
	}

	void advanceTo(int minute) override {
		while(!this->customers.empty() || !this->customers_toLeave.empty()) {
			Client* current = &this->customers.front().data1;
			// std::cout << current->arriveMinute << current->banana << current->schweppes << current->maxWaitTime << std::endl;

			if (!this->customers.empty() && !checkIfCustomerWillLeaveBefore(current->arriveMinute)) {
				// std::cout << "no one will leave" << std::endl;
				if (!checkStorage(current->banana, current->schweppes)) {
					// std::cout << "CUSTOMER CANT take products" << std::endl;

					if (checkIfWorkerWillBeDoneBefore(current->arriveMinute)) {
						// std::cout << "a worker will be done before this customer" << std::endl;

						int _time = this->busyWorkers.front().time + 60;
						if (_time > minute) {
							break;
						}
						freeWorker(current->arriveMinute);
						while (checkIfLongestWhaitingCustomerCanLeave()) {
							// std::cout << "longest whaiting customer can leave" << std::endl;

							customerLeave(this->customers_toLeave.front().data2, _time, this->customers_toLeave.front().data1.banana, this->customers_toLeave.front().data1.schweppes);
							this->customers_toLeave.erase(this->customers_toLeave.begin());
						}
					} else {
						// std::cout << "no worker will be done before this customer" << std::endl;
						if (current->arriveMinute > minute) {
							break;
						}
						sendWorkersIfNeeded(current);
						// std::cout << "worker sent if needed" << std::endl;
						
						addCustomerToWhaiting(this->customers.front());
						// std::cout << "customer added to whaiting" << std::endl;

						this->customers.pop();
					}
				} else {
						// std::cout << "customer can leave with wanted products" << std::endl;
					if (current->arriveMinute > minute) {
						break;
					}
					customerLeave(this->customers.front().data2, current->arriveMinute, current->banana, current->schweppes);
					this->customers.pop();
				}
			} else {
				// std::cout << "customer will end whaiting time" << std::endl;

				Client *customerToLeave = &this->customers_toLeave.back().data1;

				if (checkIfWorkerWillBeDoneBefore(customerToLeave->arriveMinute + customerToLeave->maxWaitTime)) {
						// std::cout << "a worker will be done before this customer" << std::endl;
						// std::cout << customerToLeave->arriveMinute << "+" << customerToLeave->maxWaitTime << std::endl;
						// std::cout << customers_toLeave.size()<< std::endl;
						//bug to fix

					int _time = this->busyWorkers.front().time + 60;
					if (_time > minute) {
						break;
					}
					freeWorker(customerToLeave->arriveMinute + customerToLeave->maxWaitTime);
					while(checkIfLongestWhaitingCustomerCanLeave()) {
							// std::cout << "longest whaiting customer can leave" << std::endl;

						customerLeave(this->customers_toLeave.front().data2, _time, this->customers_toLeave.front().data1.banana, this->customers_toLeave.front().data1.schweppes);
						this->customers_toLeave.erase(this->customers_toLeave.begin());
					}
				} else {
					// std::cout << "customer leave because cant whait more" << std::endl;
					if (customerToLeave->arriveMinute + customerToLeave->maxWaitTime> minute) {
						break;
					}
					customerLeave(this->customers_toLeave.back().data2, customerToLeave->arriveMinute + customerToLeave->maxWaitTime, (customerToLeave->banana <= storage->bananaQuantity ? customerToLeave->banana : storage->bananaQuantity), (customerToLeave->schweppes <= storage->schweppesQuantity ? customerToLeave->schweppes : storage->schweppesQuantity));

					this->customers_toLeave.pop_back();
				}
			}
		}

		while (!this->busyWorkers.empty()) {
			if (this->busyWorkers.front().time + 60 > minute) {
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

	void sendWorker(int time, ResourceType product) {
		if (this->freeWorkers) {
			this->freeWorkers--;
			this->busyWorkers.push(Worker(time, product));
			// std::cout << "send worker check01" << std::endl;

			this->actionHandler->onWorkerSend(this->busyWorkers.back().time,this->busyWorkers.back().product);
			// std::cout << "send worker check02" << std::endl;

			// this->busyWorkers.back().sendMessage(); 
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
			// this->busyWorkers.front()->doneMessage();
			this->actionHandler->onWorkerBack(this->busyWorkers.front().time+60,this->busyWorkers.front().product);
			this->busyWorkers.pop();
			this->freeWorkers++;
		} 
	}

	bool checkIfCustomerWillLeaveBefore(int time) {
		if (this->customers_toLeave.empty()) {
			return false;
		}
		return (this->customers_toLeave.back().data1.arriveMinute + this->customers_toLeave.back().data1.maxWaitTime <= time);
	}

	bool checkStorage(int bananas, int schweppes) {
		// std::cout << "storageCheck" << std::endl;
		// std::cout << this->storage->bananaQuantity << std::endl;
		return (this->storage->bananaQuantity >= bananas && this->storage->schweppesQuantity >= schweppes);
	}

	bool checkIfWorkerWillBeDoneBefore(int time) {
		if (this->busyWorkers.empty()) {
			return false;
		}
		return (this->busyWorkers.front().time + 60 <= time);
	}

	void sendWorkersIfNeeded(Client* current) {
		//send worker for the right product
		//if more than 100 is wanted by a customer?
		//if you have 50 someone wants 60 and while whaiting another customer wants 20?

		int neededBananas = current->banana - (this->storage->bananaQuantity + this->expectedStorage->bananaQuantity);
		int neededSchweppes = current->schweppes - (this->storage->schweppesQuantity + this->expectedStorage->schweppesQuantity);
		// std::cout << "send worker check1" << std::endl;

		while (this->freeWorkers > 0 && (neededSchweppes > 0 || neededBananas > 0))
		{
			// std::cout << "send worker check2" << std::endl;

			if (neededBananas >= neededSchweppes && neededBananas > 0) {
				// std::cout << "send worker check4" << std::endl;

				sendWorker(current->arriveMinute, ResourceType::banana);
				// std::cout << "send worker check5" << std::endl;

				neededBananas -= 100;
			} else if (neededSchweppes >= neededBananas && neededSchweppes > 0) {
				sendWorker(current->arriveMinute, ResourceType::schweppes);
				neededSchweppes -= 100;
			}
			// std::cout << "send worker check3" << std::endl;

		}
	}

	void addCustomerToWhaiting(Pair<Client,int> c) {
		this->customers_toLeave.push_back(c);
	}

	void customerLeave(int idNumber, int time, int bananas, int schweppes) {
		this->storage->bananaQuantity -= bananas;
		this->storage->schweppesQuantity -= schweppes;
		this->actionHandler->onClientDepart(idNumber, time, bananas, schweppes);
		// std::cout << idNumber << " " << time << " " << bananas << " " << schweppes << std::endl;
	}

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