#pragma once

class Student{
private:
  char* name;
  unsigned int fn;
  //Program program;
  char* program;
  unsigned int groupe;
  unsigned int year;
  char* status;
  double averageGrade;

  void calculateAverageGrade();

  Student& setName(char*);
  Student& setFn(unsigned int);
  Student& setProgram(char*);
  Student& setGroupe(unsigned int);
  Student& setYear(unsigned int);
  Student& setStatus(char*);

public:
  Student();

  char* getName();
  unsigned int getFn();
  char* getProgram();
  unsigned int getGroupe();
  unsigned int getYear();
  char* getStatus();
  double getAverageGrade();
  
  Student& print ();
  Student& enroll (unsigned int fn, char* program, unsigned int groupe);
  Student& advance ();
  Student& change (char* option, char* value);
  Student& graduate ();
  Student& interrupt ();
  Student& resume ();
  Student& enrollin (char* course);
  Student& addGrade (char* course, double grade);
  Student& report ();
};