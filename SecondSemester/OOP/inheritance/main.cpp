#include <iostream>

class CountedObj
{
public:
   CountedObj() {++total_;}
   CountedObj(const CountedObj& obj) {if(this != &obj) ++total_;}
   ~CountedObj() {--total_;}

   static size_t OustandingObjects() {return total_;}

private:
   static size_t total_;
};

class MyClass : CountedObj
{};