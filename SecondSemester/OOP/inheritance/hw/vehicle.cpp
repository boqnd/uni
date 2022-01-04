#pragma once
#pragma once

class Vehicle {
protected:
  double weight;
  double maxSpeed;
  double price;

public:
  double getWeight() {
    return weight;
  }

  double getMaxSpeed() {
    return maxSpeed;
  }

  double getPrice() {
    return price;
  }

  virtual void print() = 0;
};