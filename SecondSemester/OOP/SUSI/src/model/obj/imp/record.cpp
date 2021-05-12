#pragma once

#include "../../../../include/record.h"

Record::Record() {
  this->student = nullptr;
  this->discipline = nullptr;
  this->grade = 0;
}

Record::Record(Record& other) {
  this->student = other.getStudent();
  this->discipline = other.getDiscipline();
  this->grade = other.getGrade();
}

Record::Record(const Record& other) {
  this->student = other.getStudent();
  this->discipline = other.getDiscipline();
  this->grade = other.getGrade();
}

Record& Record::operator=(const Record& other) {
  this->student = other.getStudent();
  this->discipline = other.getDiscipline();
  this->grade = other.getGrade();

  return *this;
}

Record::~Record() {
  this->student = nullptr;
  this->discipline = nullptr;
  this->grade = 0;
}

Student* Record::getStudent() const {
  return this->student;
}

Discipline* Record::getDiscipline() const {
  return this->discipline;
}

const double Record::getGrade() const {
  return this->grade;
}

void Record::setStudent(Student* _student) {
  this->student = _student;
}

void Record::setDiscipline(Discipline* _discipline) {
  this->discipline = _discipline;
}

void Record::setGrade(double _grade) {
  this->grade = _grade;
}

void Record::saveToFile(char* fileName) {
  std::ofstream out (fileName, std::ofstream::app);

  out <<  "Record" << " " <<
          ((this->student != nullptr) ? (this->student->getFn()) : (0)) << " " <<
          ((this->discipline != nullptr) ? (this->discipline->getName()) : ("<no-discipline>")) << " " <<
          this->grade << std::endl ;

  out.close();
}