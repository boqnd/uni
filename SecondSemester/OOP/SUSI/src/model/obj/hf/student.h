#pragma once

#include "../../../../include/student.h"

class Student{
private:
  String name;
  unsigned int fn;
  Program program;
  unsigned int group;
  unsigned int year;
  Status status;
  double averageGrade;

  // void calculateAverageGrade();
public:
  Student();
  Student(Student&);
  Student(const Student&);
  Student& operator=(const Student&);
  ~Student();

  const String getName() const;
  const unsigned int getFn() const;
  const Program getProgram() const;
  const unsigned int getGroup() const;
  const unsigned int getYear() const;
  const Status getStatus() const;
  const double getAverageGrade() const;

  void setName(String&);
  void setFn(unsigned int);
  void setProgram(Program&);
  void setGroup(unsigned int);
  void setYear(unsigned int);
  void setStatus(Status);
  
  void print ();
  void enroll (unsigned int fn, Program program, unsigned int group);
  void advance ();
  void change (String option, String value);
  void graduate ();
  void interrupt ();
  void resume ();
  void enrollin (char* course);
  void addGrade (Discipline discipline, double grade);
  void report ();

  void saveToFile(char* fileName);
};