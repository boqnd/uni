#pragma once

#include "../../../../include/program.h"

Program::Program() {
  String defaultString;
  Vector<Discipline> defaultVector;

  this->name = defaultString;
  this->disciplines = defaultVector;
}

Program::Program(Program& other) {
  this->name = other.getName();
  this->disciplines = other.getDisciplines();
}

Program::Program(const Program& other) {
  this->name = other.getName();
  this->disciplines = other.getDisciplines();
}

Program& Program::operator=(const Program& other) {
  this->name = other.getName();
  this->disciplines = other.getDisciplines();

  return *this;
}

Program::~Program() {
  String defaultString;
  Vector<Discipline> defaultVector;

  this->name = defaultString;
  this->disciplines = defaultVector;
}

const String Program::getName() const {
  return this->name;
}

const Vector<Discipline> Program::getDisciplines() const {
  return this->disciplines;
}

void Program::setName(String& other) {
  this->name = other;
}
