#include "string.h"
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
int String::length(const char* other) {
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

//Operator= with `other` char*
String& String::operator=(const char* other) {
  if (&other != nullptr) {
    this->destroy();
    this->setData(other);
  }
  return *this;
}

//Operator[] returns the `i`-th char of the string, or '\0'
char String::operator[](const unsigned int i) {
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
int String::length() {
  return length(this->data);
}

//Out stream
std::ostream& operator<<(std::ostream& out, String& str) {
  out << str.data;

  return out;
}

std::istream& operator>>(std::istream& in, String& str) {
  char temp[128];

  //getline(temp, in);

  //this->setData(temp);

  return in;
}

