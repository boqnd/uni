#pragma once

#include "../../../../include/record.h"

Record::Record() {
  Student defaultStudent;
  Discipline defaultDiscipline;

  this->student = defaultStudent;
  this->discipline = defaultDiscipline;
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
  Student defaultStudent;
  Discipline defaultDiscipline;

  this->student = defaultStudent;
  this->discipline = defaultDiscipline;
  this->grade = 0;
}

const Student Record::getStudent() const {
  return this->student;
}

const Discipline Record::getDiscipline() const {
  return this->discipline;
}

const double Record::getGrade() const {
  return this->grade;
}