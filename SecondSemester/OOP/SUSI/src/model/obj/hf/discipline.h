#pragma once

#include "../../../../include/discipline.h"

class Discipline {
private:
  String name;
  bool required;
  unsigned int year;

public:
  Discipline();
  Discipline(Discipline&);
  Discipline& operator=(const Discipline&);
  ~Discipline();
};