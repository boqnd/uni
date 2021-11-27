#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct Storage {
  int bananaQuantity;
  int schweppesQuantity;
  Storage() : bananaQuantity(0), schweppesQuantity(0) {}
  ~Storage() {
    this->bananaQuantity = 0;
    this->schweppesQuantity = 0;
  }
};

enum Product { banana, schweppes };

struct Worker {
  int time;
  Product product;

  Worker(int time, Product product) : time(time), product(product) {}

  void sendMessage() {
    std::cout << "W " << this->time << " ";
    switch (this->product) {
      case banana: 
        std::cout << "banana" << std::endl;
        break;
      case schweppes:
        std::cout << "schweppes" << std::endl;
        break;
      default:
        break;
    }
  }

  void doneMessage() {
    std::cout << "D " << this->time + 60 << " ";
    switch (this->product) {
      case banana: 
        std::cout << "banana" << std::endl;
        break;
      case schweppes:
        std::cout << "schweppes" << std::endl;
        break;
      default:
        break;
    }
  }
};

struct Customer {
  int idNumber;
  int time;
  int bananaQuantity;
  int schweppesQuantity;
  int whaitTime;

  Customer(int idNumber, int time, int bananaQuantity, int schweppesQuantity, int whaitTime) : idNumber(idNumber), time(time), bananaQuantity(bananaQuantity), schweppesQuantity(schweppesQuantity), whaitTime(whaitTime) {}
};

class Shop {
  private:
    size_t freeWorkers;
    std::queue<Worker*> busyWorkers;
    std::queue<Customer*> customers;
    std::vector<Customer*> customers_toLeave;
    Storage* storage;
    Storage* expectedStorage;

    void clear() {
      this->freeWorkers = 0;
      while(!this->busyWorkers.empty()) this->busyWorkers.pop();
      while(!this->customers.empty()) this->customers.pop();
      this->customers_toLeave.clear();
      // while(!this->customers_toLeave.empty()) this->customers_toLeave.pop();
      delete this->storage;
      delete this->expectedStorage;
    }

    void fillData() {
      int nWorkers, nCustomers;
      std::cin >> nWorkers >> nCustomers;

      this->freeWorkers = nWorkers;
      for (size_t i = 0; i < nCustomers; i++)
      {
        int t, b, s, w;
        std::cin >> t >> b >> s >> w;
        this->customers.push(new Customer(i,t,b,s,w));
      }
    }

  public:

    Shop() {
      this->storage = new Storage();
      this->expectedStorage = new Storage();
    }

    ~Shop() {
      this->clear();
    }

    void sendWorker(int time, Product product) {
      if (this->freeWorkers) {
        this->freeWorkers--;
        this->busyWorkers.push(new Worker(time, product));
        this->busyWorkers.back()->sendMessage();
        switch (product)
        {
          case banana:
            this->expectedStorage->bananaQuantity += 100;
            break;
          case schweppes:
            this->expectedStorage->schweppesQuantity += 100;
            break;
          default:
            break;
        }
      }
    }

    void freeWorker(int time) {
      if (this->busyWorkers.front()->time+60 <= time) {
        switch (this->busyWorkers.front()->product) {
          case banana:
            this->storage->bananaQuantity += 100;
            this->expectedStorage->bananaQuantity -= 100;
            break;
          case schweppes:
            this->storage->schweppesQuantity += 100;
            this->expectedStorage->schweppesQuantity -= 100;
            break;
          default:
            break;
        }
        this->busyWorkers.front()->doneMessage();
        this->busyWorkers.pop();
        this->freeWorkers++;
      } 
    }

    // Customer* getFirstCustomerToLeaveBefore(int time) {
    //   Customer* min = nullptr;
    //   for (size_t i = 0; i < this->customers_toLeave.size(); i++)
    //   {
    //     if (min > )
    //     {
    //       /* code */
    //     }
        
    //   }
      
    // }

    bool checkIfCustomerWillLeaveBefore(int time) {
      if (this->customers_toLeave.empty()) {
        return false;
      }
      return (this->customers_toLeave.back()->time + this->customers_toLeave.back()->whaitTime <= time);
    }

    bool checkStorage(int bananas, int schweppes) {
      return (this->storage->bananaQuantity >= bananas && this->storage->schweppesQuantity >= schweppes);
    }

    bool checkIfWorkerWillBeDoneBefore(int time) {
      if (this->busyWorkers.empty()) {
        return false;
      }
      return (this->busyWorkers.front()->time + 60 <= time);
    }

    void sendWorkersIfNeeded(Customer* current) {
      //send worker for the right product
      //if more than 100 is wanted by a customer?
      //if you have 50 someone wants 60 and while whaiting another customer wants 20?

      int neededBananas = current->bananaQuantity - (this->storage->bananaQuantity + this->expectedStorage->bananaQuantity);
      int neededSchweppes = current->schweppesQuantity - (this->storage->schweppesQuantity + this->expectedStorage->schweppesQuantity);
      while (this->freeWorkers > 0 && (neededSchweppes > 0 || neededBananas > 0))
      {
        if (neededBananas >= neededSchweppes && neededBananas > 0) {
          sendWorker(current->time, banana);
          neededBananas -= 100;
        } else if (neededSchweppes >= neededBananas && neededSchweppes > 0) {
          sendWorker(current->time, schweppes);
          neededSchweppes -= 100;
        }
      }
    }

    void addCustomerToWhaiting(Customer* c) {
      this->customers_toLeave.push_back(c);
    }

    void customerLeave(int idNumber, int time, int bananas, int schweppes) {
      this->storage->bananaQuantity -= bananas;
      this->storage->schweppesQuantity -= schweppes;
      std::cout << idNumber << " " << time << " " << bananas << " " << schweppes << std::endl;
    }

    bool checkIfLongestWhaitingCustomerCanLeave() {
      if (this->customers_toLeave.empty()) {
        return false;
      }
      return checkStorage(this->customers_toLeave.front()->bananaQuantity, this->customers_toLeave.front()->schweppesQuantity);
    }
    /*
    5 3
    0 10 10 100
    1 10 10 2
    10 10 10 50
    W 0 banana
    W 0 schweppes
    hhh
    hhhraas
    1 3 0 0
    fish: Job 1, './"$argv"' terminated by signal SIGSEGV (Address boundary error)
*/
//check error
    void StartDay() {
      this->fillData();

      while(!this->customers.empty() || !this->customers_toLeave.empty()) {
        Customer* current = this->customers.front();

        if (!this->customers.empty() && !checkIfCustomerWillLeaveBefore(current->time)) {
          // std::cout << "no one will leave" << std::endl;
          if (!checkStorage(current->bananaQuantity, current->schweppesQuantity)) {
            // std::cout << "CUSTOMER CANT take products" << std::endl;

            if (checkIfWorkerWillBeDoneBefore(current->time)) {
              // std::cout << "a worker will be done before this customer" << std::endl;

              int _time = this->busyWorkers.front()->time + 60;
              freeWorker(current->time);
              while (checkIfLongestWhaitingCustomerCanLeave()) {
                // std::cout << "longest whaiting customer can leave" << std::endl;

                customerLeave(this->customers_toLeave.front()->idNumber, _time, this->customers_toLeave.front()->bananaQuantity, this->customers_toLeave.front()->schweppesQuantity);
                this->customers_toLeave.erase(this->customers_toLeave.begin());
              }
            } else {
              // std::cout << "no worker will be done before this customer" << std::endl;

              sendWorkersIfNeeded(current);

              addCustomerToWhaiting(current);
              // std::cout << "customer added to whaiting" << std::endl;

              this->customers.pop();
            }
          } else {
              // std::cout << "customer can leave with wanted products" << std::endl;

            customerLeave(current->idNumber, current->time, current->bananaQuantity, current->schweppesQuantity);
            this->customers.pop();
          }
        } else {
          // std::cout << "customer will end whaiting time" << std::endl;

          Customer *customerToLeave = this->customers_toLeave.back();

          if (checkIfWorkerWillBeDoneBefore(customerToLeave->time + customerToLeave->whaitTime)) {
              // std::cout << "a worker will be done before this customer" << std::endl;

            int _time = this->busyWorkers.front()->time + 60;
            freeWorker(customerToLeave->time + customerToLeave->whaitTime);
            while(checkIfLongestWhaitingCustomerCanLeave()) {
                // std::cout << "longest whaiting customer can leave" << std::endl;

              customerLeave(this->customers_toLeave.front()->idNumber, _time, this->customers_toLeave.front()->bananaQuantity, this->customers_toLeave.front()->schweppesQuantity);
              this->customers_toLeave.erase(this->customers_toLeave.begin());
            }
          } else {
            // std::cout << "customer leave because cant whait more" << std::endl;

            customerLeave(customerToLeave->idNumber, customerToLeave->time + customerToLeave->whaitTime, (customerToLeave->bananaQuantity <= storage->bananaQuantity ? customerToLeave->bananaQuantity : storage->bananaQuantity), (customerToLeave->schweppesQuantity <= storage->schweppesQuantity ? customerToLeave->schweppesQuantity : storage->schweppesQuantity));

            this->customers_toLeave.pop_back();
          }
        }
      }

      if(!this->customers_toLeave.empty()) {
        std::cout << this->customers_toLeave.size() << " customers are still whaiting" <<std::endl;
      }
    }
};



int main() {
  int W = 5;
  int C = 4;

  Shop shop;
  shop.StartDay();


}

/*

Примерен вход:
5(workers) 4(customers)
0(minute) 10(bananas) 0(schweppes) 10(whait time)
45(minute) 35(bananas) 0(schweppes) 30(whait time)
46(minute) 30(bananas) 20(schweppes) 100(whait time)
200(minute) 10(bananas) 10(schweppes) 1(whait time)

Изход:
W 0(minute) banana
0(id) 10(minute) 0(banana) 0(schweppes)
W 46(minute) schweppes
D 60(minute) banana
1(id) 60(minute) 35(banana) 0(schweppes)
D 106(minute) schweppes
2(id) 106(minute) 30(banana) 20(schweppes)
3(id) 200(minute) 10(banana) 10(schweppes)

*/