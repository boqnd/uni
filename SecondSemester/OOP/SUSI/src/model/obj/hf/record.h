#pragma once

#include "../../../../include/record.h"

class Record {
private:
  Student student;
  Discipline discipline;
  double grade;

public:
  Record();
  Record(Record&);
  Record(const Record&);
  Record& operator=(const Record&);
  ~Record();

  const Student getStudent() const;
  const Discipline getDiscipline() const;
  const double getGrade() const;

  void saveToFile(char* fileName);
};