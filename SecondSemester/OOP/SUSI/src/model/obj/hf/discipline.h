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
  Discipline(const Discipline&);
  Discipline& operator=(const Discipline&);
  ~Discipline();

  const String getName() const;
  const bool isRequired() const;
  const unsigned int getYear() const;

  void setName(String&);
  void setName(const char*);
  void setRequired(bool);
  void setYear(unsigned int);

  void saveToFile(char* fileName);
};