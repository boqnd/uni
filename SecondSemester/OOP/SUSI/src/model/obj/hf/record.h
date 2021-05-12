#pragma once

#include "../../../../include/record.h"

class Record {
private:
  Student* student;
  Discipline* discipline;
  double grade;

public:
  Record();
  Record(Record&);
  Record(const Record&);
  Record& operator=(const Record&);
  ~Record();

  Student* getStudent() const;
  Discipline* getDiscipline() const;
  const double getGrade() const;

  void setStudent(Student*);
  void setDiscipline(Discipline*);
  void setGrade(double);

  void saveToFile(char* fileName);
};