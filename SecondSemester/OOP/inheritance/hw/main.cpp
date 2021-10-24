#include <iostream>
#include <vector>
#include <string>
#include "vehicle.cpp"
#include "airplane.cpp"
#include "car.cpp"
#include "ship.cpp"

void printSortedByPrice(std::vector<Vehicle*> vehicles) {
  std::cout << std::endl << "Sorted vehicles by price:" << std::endl;
  std::cout << "-------------------------" << std::endl;
  
  while (vehicles.size() > 0)
  {
    double minPrice = vehicles[0]->getPrice();
    int index = 0;

    for (size_t i = 1; i < vehicles.size(); i++)
    {
      if (vehicles[i]->getPrice() < minPrice) {
        minPrice = vehicles[i]->getPrice();
        index = i;
      }
    }

    vehicles[index]->print();
    vehicles.erase(vehicles.begin() + index);
  }

  std::cout << "-------------------------" << std::endl << std::endl;
}

void printAllVehiclesFasterThan200(std::vector<Vehicle*> vehicles) {
  std::cout << std::endl << "All vehicles faster than 200km/h:" << std::endl;
  std::cout << "-------------------------" << std::endl;
  
  for (size_t i = 1; i < vehicles.size(); i++)
  {
    if (vehicles[i]->getMaxSpeed() >= 200) {
      vehicles[i]->print();
    }
  }

  std::cout << "-------------------------" << std::endl << std::endl;
}

int main() {
  std::vector<Vehicle*> vehicles;

  Car c(2,200,3000,Light);
  Ship s(10,80,30000, 50);
  Airplane a(100,600,300000, 6000);

  vehicles.push_back(&a);
  vehicles.push_back(&c);
  vehicles.push_back(&s);
  vehicles.push_back(&a);
  vehicles.push_back(&c);
  vehicles.push_back(&a);
  vehicles.push_back(&s);
  vehicles.push_back(&a);
  vehicles.push_back(&s);
  vehicles.push_back(&c);
  vehicles.push_back(&s);
  vehicles.push_back(&a);
  vehicles.push_back(&c);
  vehicles.push_back(&c);

  printSortedByPrice(vehicles);
  printAllVehiclesFasterThan200(vehicles);

  return 0;
}