#pragma once

#include "../../../../include/student.h"

Student::Student() {
  String defaultString;
  Program defaultProgram;

  this->name = defaultString;
  this->fn = 0;
  this->program = defaultProgram;
  this->groupe = 0;
  this->year = 0;
  this->status = NotEnrolled;
  this->averageGrade = 0;
}

Student::Student(Student& other) {
  this->name = other.getName();
  this->fn = other.getFn();
  this->program = other.getProgram();
  this->groupe = other.getGroupe();
  this->year = other.getYear();
  this->status = other.getStatus();
  this->averageGrade = other.getAverageGrade();
}

Student::Student(const Student& other) {
  this->name = other.getName();
  this->fn = other.getFn();
  this->program = other.getProgram();
  this->groupe = other.getGroupe();
  this->year = other.getYear();
  this->status = other.getStatus();
  this->averageGrade = other.getAverageGrade();
}

Student& Student::operator=(const Student& other) {
  this->name = other.getName();
  this->fn = other.getFn();
  this->program = other.getProgram();
  this->groupe = other.getGroupe();
  this->year = other.getYear();
  this->status = other.getStatus();
  this->averageGrade = other.getAverageGrade();

  return *this;
}

Student::~Student() {
  String defaultString;
  Program defaultProgram;

  this->name = defaultString;
  this->fn = 0;
  this->program = defaultProgram;
  this->groupe = 0;
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

void Student::setProgram (Program& _program) {
  this->program = _program;
}

void Student::setGroupe (unsigned int _groupe) {
  this->groupe = _groupe;
}

void Student::setYear (unsigned int _year) {
  this->year = _year;
}

void Student::setStatus (Status _status) {
  this->status = _status;
}

const String Student::getName() const {
  return this->name;
}

const unsigned int Student::getFn() const {
  return this->fn;
}

const Program Student::getProgram() const {
  return this->program;
}

const unsigned int Student::getGroupe() const {
  return this->groupe;
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

void Student::print () {
  std::cout << std::endl;
  std::cout << "Student " << this->fn << std::endl;
  std::cout << "---------------" << std::endl;
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Program: " << this->program.getName() << std::endl;
  std::cout << "Groupe: " << this->groupe << std::endl;
  std::cout << "Year: " << this->year << std::endl;
  std::cout << "Status: " << this->status << " (0: not enrolled, 1: interupted, 2: enrolled, 3: graduated)" << std::endl;
  std::cout << "Average Grade: " << this->averageGrade << std::endl;
  std::cout << std::endl;
}

void Student::enroll (unsigned int _fn, Program _program, unsigned int _groupe) {
  this->setFn(_fn);
  this->setProgram(_program);
  this->setGroupe(_groupe);
  this->setYear(1);
  this->setStatus(Enrolled);
}

void Student::advance () {
  this->setYear(this->getYear() + 1);
}

void Student::change (char* option, char* value) {
  //not now
}

void Student::graduate () {
  this->setStatus(Gradueted);
}

void Student::interrupt () {
  this->setStatus(Interupted);
}

void Student::resume () {
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




