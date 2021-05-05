#pragma once

#include "../../../../include/program.h"

class Program {
private:
  String name;
  Vector<Discipline> disciplines;

public:
  Program();
  Program(Program&);
  Program(const Program&);
  Program& operator=(const Program&);
  ~Program();

  const String getName() const;
  const Vector<Discipline> getDisciplines() const;

  void setName(String&);
};