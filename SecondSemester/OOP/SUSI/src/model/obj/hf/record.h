#pragma once

#include "../../../../include/record.h"

class Record {
private:
  Student& student;
  Discipline& discipline;
  double grade;

public:
  Record();
  Record(Record&);
  Record& operator=(const Record&);
  ~Record();
};