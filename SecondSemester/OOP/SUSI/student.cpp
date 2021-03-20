#include "student.h"
#include <cstring>
#include <iostream>

Student::Student () {
  name = new char[0];
  fn = 0;
  program = new char[0];
  groupe = 0;
  year = 0;
  status = new char[0];
  averageGrade = 0;
}

Student& Student::setName (char* _name) {
  if (_name != nullptr)
  {
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
  }
  return *this;
}

Student& Student::setFn (unsigned int _fn) {
  this->fn = _fn;
  return *this;
}

Student& Student::setProgram (char* _program) {
  if (_program != nullptr)
  {
    this->program = new char[strlen(_program) + 1];
    strcpy(this->program, _program);
  }
  return *this;
}

Student& Student::setGroupe (unsigned int _groupe) {
  this->groupe = _groupe;
  return *this;
}

Student& Student::setYear (unsigned int _year) {
  this->year = _year;
  return *this;
}

Student& Student::setStatus (char* _status) {
  if (_status != nullptr)
  {
    this->status = new char[strlen(_status) + 1];
    strcpy(this->status, _status);
  }
  return *this;
}

char* Student::getName () {
  return this->name;
}

unsigned int Student::getFn () {
  return this->fn;
}

char* Student::getProgram () {
  return this->program;
}

unsigned int Student::getGroupe () {
  return this->groupe;
}

unsigned int Student::getYear () {
  return this->year;
}

char* Student::getStatus () {
  return this->status;
}

double Student::getAverageGrade () {
  return this->averageGrade;
}

Student& Student::print () {
  std::cout << std::endl;
  std::cout << "Student " << this->fn << std::endl;
  std::cout << "---------------" << std::endl;
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Program: " << this->program << std::endl;
  std::cout << "Groupe: " << this->groupe << std::endl;
  std::cout << "Year: " << this->year << std::endl;
  std::cout << "Status: " << this->status << std::endl;
  std::cout << "Average Grade: " << this->averageGrade << std::endl;
  std::cout << std::endl;

  return *this;
}

Student& Student::enroll (unsigned int _fn, char* _program, unsigned int _groupe) {
  this->setFn(_fn);
  this->setProgram(_program);
  this->setGroupe(_groupe);
  this->setYear(1);
  this->setStatus("Enrolled");

  return *this;
}

Student& Student::advance () {
  this->setYear(this->getYear() + 1);

  return *this;
}

Student& Student::change (char* option, char* value) {
  //not now

  return *this;
}

Student& Student::graduate () {
  this->setStatus("Gradueted");

  return *this;
}

Student& Student::interrupt () {
  this->setStatus("Interupted");

  return *this;
}

Student& Student::resume () {
  this->setStatus("Enrolled");

  return *this;
}

Student& Student::enrollin (char* course) {
  //not now

  return *this;
}

Student& Student::addGrade (char* course, double grade) {
  //not now

  return *this;
}

Student& Student::report () {
  //not now

  return *this;
}




