#include <iostream>
#include "implementation.cpp"

struct TestStore : ActionHandler {
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

int main() {
  Store* store = createStore();
  TestStore* t = new TestStore();

  store->setActionHandler(t);

  int nWorkers, nCustomers;
  std::cin >> nWorkers >> nCustomers;
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
