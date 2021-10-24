#pragma once
#include "vehicle.cpp"

class Airplane : public Vehicle {
private:
  double maxHeight;

public:
  Airplane(double _weight, double _maxSpeed, double _price, double _maxHeight) {
    this->weight = _weight;
    this->maxSpeed = _maxSpeed;
    this->price = _price;
    this->maxHeight = _maxHeight;
  }

  double getMaxHeight() {
    return maxHeight;
  }

  void print() {
    std::cout << "Airplane { " << 
    "weight: " << this->weight << ", " <<
    "maxSpeed: " << this->maxSpeed << ", " <<
    "price: " << this->price << ", " <<
    "maxHeight: " << this->maxHeight << " }" << std::endl;
  }
};