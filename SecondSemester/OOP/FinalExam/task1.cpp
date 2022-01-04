#include <iostream>
#include <cstring>

// enum Type {End, Middle, Normal};

class Station {
  protected:
  char* name;
  unsigned int serialNum;
  int capacity;
  int trainCount;
  bool signal;
  Station* next;

  public:
  Station(char _name[20], int _capacity, Station* _next) : capacity(_capacity)
  {
    name = new char[strlen(_name)+1];
    strcpy(name,_name);
    next = _next;
  }

  bool getSignal() {return this->signal;}

  void allowDeparture() { signal = true; }

  void forbidDeparture() { signal = false; }

  void close() {}
  
};

class EndStation : public Station {

  public:
  EndStation(char _name[20], int _capacity) : Station(_name, _capacity, nullptr) {}

};

class CrossStation : public Station {

  private:
  bool signal2;

  public:
  CrossStation(char _name[20], int _capacity, Station* _next) : Station(_name, _capacity, _next) {}

  bool getSignal2() {return this->signal2;}

  void allowDeparture2() { signal2 = true; }

  void forbidDeparture2() { signal2 = false; }
};

enum TrainType {Express, Fast, Normal};

class Train {
  private:
  int number;
  TrainType type;
  Station* currentStation;

  Train (int _number, TrainType _type) : number(_number), type(_type) {}
};

int main() {

  return 0;
}