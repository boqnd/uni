#pragma once

#include "../../../../include/discipline.h"

Discipline::Discipline() {
  String defaultString;

  this->name = defaultString;
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