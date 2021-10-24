#pragma once
#include "vehicle.cpp"

class Ship : public Vehicle {
private:
  double displacement;

public:  
  Ship(double _weight, double _maxSpeed, double _price, double _displacement) {
    this->weight = _weight;
    this->maxSpeed = _maxSpeed;
    this->price = _price;
    this->displacement = _displacement;
  }

  double getDisplacement() {
    return displacement;
  }

  void print() {
    std::cout << "Ship { " << 
    "weight: " << this->weight << ", " <<
    "maxSpeed: " << this->maxSpeed << ", " <<
    "price: " << this->price << ", " <<
    "displacement: " << this->displacement << " }" << std::endl;
  }
};