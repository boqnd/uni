#pragma once

#include "../../../../include/student.h"

Student::Student() {
  this->name = "<no-name>";
  this->fn = 0;
  this->program = nullptr;
  this->group = 0;
  this->year = 0;
  this->status = NotEnrolled;
  this->averageGrade = 0;
}

Student::Student(Student& other) {
  this->name = other.getName();
  this->fn = other.getFn();
  this->program = other.getProgram();
  this->group = other.getGroup();
  this->year = other.getYear();
  this->status = other.getStatus();
  this->averageGrade = other.getAverageGrade();
}

Student::Student(const Student& other) {
  this->name = other.getName();
  this->fn = other.getFn();
  this->program = other.getProgram();
  this->group = other.getGroup();
  this->year = other.getYear();
  this->status = other.getStatus();
  this->averageGrade = other.getAverageGrade();
}

Student& Student::operator=(const Student& other) {
  this->name = other.getName();
  this->fn = other.getFn();
  this->program = other.getProgram();
  this->group = other.getGroup();
  this->year = other.getYear();
  this->status = other.getStatus();
  this->averageGrade = other.getAverageGrade();

  return *this;
}

Student::~Student() {
  String defaultString;

  this->name = defaultString;
  this->fn = 0;
  this->program = nullptr;
  this->group = 0;
  this->year = 0;
  this->status = NotEnrolled;
  this->averageGrade = 0;
}

void Student::setName(String& _name) {
  this->name = _name;
}

void Student::setFn(unsigned int _fn) {
  this->fn = _fn;
}

void Student::setProgram (Program* _program) {
  this->program = _program;
}

void Student::setGroup (unsigned int _group) {
  this->group = _group;
}

void Student::setYear (unsigned int _year) {
  this->year = _year;
}

void Student::setStatus (Status _status) {
  this->status = _status;
}

void Student::setAverageGrade(double _grade) {
  this->averageGrade = _grade;
}


const String Student::getName() const {
  return this->name;
}

const unsigned int Student::getFn() const {
  return this->fn;
}

Program* Student::getProgram() const {
  return this->program;
}

const unsigned int Student::getGroup() const {
  return this->group;
}

const unsigned int Student::getYear() const {
  return this->year;
}

const Status Student::getStatus() const {
  return this->status;
}

const double Student::getAverageGrade() const {
  return this->averageGrade;
}

void Student::print() {
  std::cout << std::endl;
  std::cout << "Student " << this->fn << std::endl;
  std::cout << "---------------" << std::endl;
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Program: " << this->program->getName() << std::endl;
  std::cout << "Group: " << this->group << std::endl;
  std::cout << "Year: " << this->year << std::endl;
  std::cout << "Status: " << this->status << " (0: not enrolled, 1: interupted, 2: enrolled, 3: graduated)" << std::endl;
  std::cout << "Average Grade: " << this->averageGrade << std::endl;
  std::cout << std::endl;
}

void Student::enroll(unsigned int _fn, Program* _program, unsigned int _group) {
  this->setFn(_fn);
  this->setProgram(_program);
  this->setGroup(_group);
  this->setYear(1);
  this->setStatus(Enrolled);
}

void Student::advance() {
  this->setYear(this->getYear() + 1);
}

void Student::change(String option, String value) {
  if (option == "program")
  {
    Program newProgram;
    newProgram.setName(value);
    this->program = new Program(newProgram);
  } else if(option == "group") {
    this->group = value[0] - '0';
  }else if(option == "year") {
    this->year = value[0] - '0';
  }
  //more to do
}

void Student::graduate() {
  this->setStatus(Gradueted);
}

void Student::interrupt() {
  this->setStatus(Interupted);
}

void Student::resume() {
  this->setStatus(Enrolled);
}

void Student::enrollin (char* course) {
  //not now
}

void Student::addGrade (Discipline discipline, double grade) {
  //not now
}

void Student::report () {
  //not now
}

void Student::saveToFile(char* fileName) {
  std::ofstream out (fileName, std::ofstream::app);

  out  << "Student" << " " <<
          this->name << " " <<
          this->fn << " " <<
          ((this->program != nullptr) ? (this->program->getName()) : ("<no-program>")) << " " <<
          this->group << " " <<
          this->year << " " <<
          this->status << " " <<
          this->averageGrade << std::endl;

  out.close();
}