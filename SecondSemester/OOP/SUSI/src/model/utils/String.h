#pragma once
#include <iostream>
#include <cstring>
#include "Vector.h"

class String {

private:
  char* data;

  void copy(const String&);
  void destroy();
  void setData(const char*);
  int length(const char*) const;

public:
  String();
  String(const String&);
  String(const char*);
  String& operator=(const String&);
  String& operator=(const char*);
  bool operator==(const String&);
  bool operator==(const char*);
  void push_back(const char);

  //char operator[](const unsigned int);
  char operator[](const unsigned int) const;

  ~String();

  //int length();
  int length() const;
  int parseInt() const;
  double parseDouble() const;
  Vector<String> split(char) const;
  char* getData() const;

  friend std::ostream& operator<<(std::ostream& out, String&);
  friend std::ostream& operator<<(std::ostream& out, const String&);
  friend std::istream& operator>>(std::istream& in, String& str);
};

//=======
//PRIVATE
//=======

//Copy other String data into this String
void String::copy(const String& other) {
  this->setData(other.data);
}

//Set this String data equal to `other` char*
void String::setData(const char* other) {
  this->data = new char[length(other) + 1];
  for (size_t i = 0; i < length(other); i++) {
    this->data[i] = other[i];
  }
  data[length(other)] = '\0';
}

//Destroy (delete) this String's data
void String::destroy() {
  delete[] data;
}

//Get length of `other` char*
int String::length(const char* other) const{
  int length = 0;
  while (other[length] != '\0') { length++; }
  return length;
};


//======
//PUBLIC
//======

//Default constructor
String::String() {
  this->data = new char[0];
}

//Copy constructor
String::String(const String& other) {
  this->copy(other);
}

//Constructor with char*
String::String(const char* other) {
  this->setData(other);
}

//Operator= with `other` String 
String& String::operator=(const String& other) {
  if (this != &other) {
    this->destroy();
    this->copy(other);
  }
  return *this;
}

bool String::operator==(const String& other) {
  int index = 0;
  while (other[index] != '\0') { 
    if (this->data[index] != other[index])
    {
      return false;
    }
    index++;
  }

  if (this->data[index] == '\0')
  {
    return true;
  }else {
    return false;
  }
}

bool String::operator==(const char* other) {
  int index = 0;
  while (other[index] != '\0') { 
    if (this->data[index] != other[index])
    {
      return false;
    }
    index++;
  }

  if (this->data[index] == '\0')
  {
    return true;
  }else {
    return false;
  }
}

//Operator= with `other` char*
String& String::operator=(const char* other) {
  this->destroy();
  this->setData(other);
  return *this;
}

void String::push_back(const char _newChar) {
  int size = this->length();
  this->data[size++] = _newChar;
  this->data[size] = '\0';
}


//Operator[] returns the `i`-th char of the string, or '\0'
// char String::operator[](const unsigned int i) {
//   if(i < this->length()) {
//     return this->data[i];
//   }
//   return '\0';
// }

char String::operator[](const unsigned int i) const {
  if(i < this->length()) {
    return this->data[i];
  }
  return '\0';
}

//Destructor
String::~String() {
  this->destroy();
}

//Get length of this String
int String::length() const{
  return length(this->data);
}

int String::parseInt() const {
  int result = 0;
  for (size_t i = 0; this->data[i] != '\0'; i++)
  {
    if (this->data[i] < '0' || this->data[i] > '9')
    {
      throw std::invalid_argument( "received non-number value" );
    }
    
    result = result*10 + (this->data[i] - '0');
  }

  return result;
  
}

double String::parseDouble() const {
  double result = 0;
  double dn = 1;
  bool beforeDecimalPoint = true;
  for (size_t i = 0; this->data[i] != '\0'; i++)
  {
    if (this->data[i] == '.' && beforeDecimalPoint) {
      beforeDecimalPoint = false;
    }else {
      if (this->data[i] < '0' || this->data[i] > '9') {
        throw std::invalid_argument( "received non-number value" );
      }

      result = result*10 + (this->data[i] - '0');
      
      if (!beforeDecimalPoint) {
        dn*=10;
      }
    }
  }
  return result/dn;
}

Vector<String> String::split(char separator) const {
  Vector<String> words;

  size_t i = 0;
  while (this->data[i] != '\0')
  {
    String curr = "";

    for (; this->data[i] != separator && this->data[i] != '\0'; i++)
    {
      curr.push_back(this->data[i]);
    }
    i++;

    words.push_back(curr);
  }
  return words;
}

char* String::getData() const {
  return this->data;
}



//Out stream
std::ostream& operator<<(std::ostream& out, String& str) {
  out << str.data;

  return out;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
  out << str.data;

  return out;
}

std::istream& operator>>(std::istream& in, String& str) {

  char buffer[1024];
  in >> buffer;

  str.destroy();
  str.data = new char[strlen(buffer) + 1];

  strcpy(str.data, buffer);

  return in;
}

bool operator==(const String& other_, const String& other) {
  int index = 0;
  while (other[index] != '\0') { 
    if (other_[index] != other[index])
    {
      return false;
    }
    index++;
  }

  if (other_[index] == '\0')
  {
    return true;
  }else {
    return false;
  }
}

