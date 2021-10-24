#pragma once
#include "vehicle.cpp"

enum Type {Light, Cargo, Luxury};

class Car : public Vehicle {
private:
  Type type;

public:
  Car(double _weight, double _maxSpeed, double _price, Type _type) {
    this->weight = _weight;
    this->maxSpeed = _maxSpeed;
    this->price = _price;
    this->type = _type;
  }

  Type getType() {
    return type;
  }

  void print() {
    std::cout << "Car { " << 
    "weight: " << this->weight << ", " <<
    "maxSpeed: " << this->maxSpeed << ", " <<
    "price: " << this->price << ", " <<
    "type: ";

    switch (this->type)
    {
    case Light:
      std::cout << "Light";
      break;
    case Cargo:
      std::cout << "Cargo";
      break;
    case Luxury:
      std::cout << "Luxury";
      break;
    default:
      break;
    }

    std::cout << " }" << std::endl;
  }
};