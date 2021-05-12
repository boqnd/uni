#pragma once

#include "../../../../include/program.h"

Program::Program() {
  Vector<Discipline*> defaultVector;

  this->name = "<no-program>";
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
  this->name = defaultString;
}

const String Program::getName() const {
  return this->name;
}

const Vector<Discipline*>& Program::getDisciplines() const {
  return this->disciplines;
}

void Program::setName(String& other) {
  this->name = other;
}

void Program::setDisciplines(Vector<Discipline*>& _disciplines) {
  this->disciplines = _disciplines;
}

void Program::addDiscipline(Discipline* _discipline) {
  this->disciplines.push_back(_discipline);
}

void Program::saveToFile(char* fileName) {
  std::ofstream out (fileName, std::ofstream::app);

  out  << "Program" << " " <<
          this->name << " " <<
          this->disciplines.getSize();

  for (size_t i = 0; i < disciplines.getSize(); i++)
  {
    out << " " << disciplines[i]->getName();
  }
  
  out << std::endl;
  
  out.close();
}