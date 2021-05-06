#pragma once

#include "../../../../include/discipline.h"

Discipline::Discipline() {
  this->name = "<no-discipline>";
  this->required = false;
  this->year = 0;
}

Discipline::Discipline(Discipline& other) {
  this->name = other.getName();
  this->required = other.isRequired();
  this->year = other.getYear();
}

Discipline::Discipline(const Discipline& other) {
  this->name = other.getName();
  this->required = other.isRequired();
  this->year = other.getYear();
}

Discipline& Discipline::operator=(const Discipline& other) {
  this->name = other.getName();
  this->required = other.isRequired();
  this->year = other.getYear();

  return *this;
}

Discipline::~Discipline() {
  String defaultString;

  this->name = defaultString;
  this->required = false;
  this->year = 0;
}

const String Discipline::getName() const {
  return this->name;
}

const bool Discipline::isRequired() const {
  return this->required;
}

const unsigned int Discipline::getYear() const {
  return this->year;
}

void Discipline::setName(String& _name) {
  this->name = _name;
}

void Discipline::setName(const char* _name) {
  this->name = _name;
}

void Discipline::setRequired(bool _required) {
  this->required = _required;
}

void Discipline::setYear(unsigned int _year) {
  this->year = _year;
}

void Discipline::saveToFile(char* fileName) {
  std::ofstream out (fileName, std::ofstream::app);

  out <<  this->name << " " <<
          this->required << " " <<
          this->year << std::endl;

  out.close();
}