#pragma once

#include "../../../../include/program.h"

class Program {
private:
  Vector<Discipline> disciplines;

public:
  Program();
  Program(Program&);
  Program& operator=(const Program&);
  ~Program();
};