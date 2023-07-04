#include "scpp.h"

StringPiece::StringPiece() {
  this->data[0] = '\0';
}

StringPiece::StringPiece(char* value) {
  this->copy(value);
}

StringPiece::StringPiece(const char* value) {
  this->copy(value);
}

StringPiece::StringPiece(const StringPiece& other) {
  this->copy(other.data);
}

StringPiece::StringPiece(StringPiece&& other) noexcept {
  memcpy(data, other.data, sizeof(data));
  other.data[0] = '\0';
}

StringPiece& StringPiece::operator=(const StringPiece& other) {
  if (this != &other) {
    this->copy(other.data);
  }
  return *this;
}

const char* StringPiece::get() const {
  return this->data;
}

void StringPiece::set(const char* value) {
  this->copy(value);
}

void StringPiece::operator<<(const char* value) {
  size_t len = strlen(this->data) + strlen(value);

  char* concat = new char[len + 1];
  strncpy(concat, this->data, 16);

  strcat(concat, value);

  this->copy(concat);
  delete[] concat;
}

void operator>>(const char* value, StringPiece& piece) {
  size_t len = strlen(piece.data) + strlen(value);

  char* concat = new char[len + 1];
  strncpy(concat, value, 16);

  strcat(concat, piece.data);

  piece.set(concat);
  delete[] concat;
}

StringPiece& StringPiece::remove_prefix(size_t k) {
  k = k < 16 ? k : 16;

  memmove(this->data, this->data + k, sizeof(this->data) - k);
  memset(this->data + sizeof(this->data) - k, '\0', k);
  return *this;
}

StringPiece& StringPiece::remove_suffix(size_t k) {
  k = k < 16 ? k+1 : 17;

  memset(this->data + sizeof(this->data) - k, '\0', k);
  return *this;
}

char& StringPiece::operator[](int index) {
  return this->data[index];
}

void StringPiece::copy(char* value) {
  strncpy(this->data, value, 16);
}

void StringPiece::copy(const char* value) {
  strncpy(this->data, value, 16);
}

//---

MyString::MyString() : count(0), data(nullptr) {}

MyString::MyString(const char* str) : count(strlen(str)), data(new char[this->count + 1]) {
  strcpy(this->data, str);
}

MyString::~MyString() {
  delete[] this->data;
  this->data = nullptr;
}

MyString::MyString(const MyString& other) : count(other.count), data(new char[this->count + 1]) {
  strcpy(this->data, other.data);
}

MyString& MyString::operator=(const MyString& other) {
  if (this != &other) {
    delete[] this->data;
    this->count = other.count;
    this->data = new char[this->count + 1];
    strcpy(this->data, other.data);
  }
  return *this;
}

MyString::MyString(MyString&& other) noexcept : count(other.count), data(other.data) {
  other.count = 0;
  other.data = nullptr;
}

size_t MyString::size() const {
  return this->count;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
  return os << str.data;
}

//---

StringCreaterPieceByPiece::StringCreaterPieceByPiece() {
  this->capacity = 0;
  this->data = nullptr;
  this->count = 0;
}

StringCreaterPieceByPiece::StringCreaterPieceByPiece(size_t _capacity) {
  this->capacity = _capacity;
  this->data = new StringPiece[capacity];
  this->count = 0;
}

StringCreaterPieceByPiece::~StringCreaterPieceByPiece() {
  delete[] this->data;
  this->data = nullptr;
  this->count = 0;
  this->capacity = 0;
}

StringCreaterPieceByPiece::StringCreaterPieceByPiece(const StringCreaterPieceByPiece& other) {
  this->capacity = other.capacity;
  this->data = new StringPiece[capacity];
  this->count = other.count;
  for (unsigned i = 0; i < this->count; i++) {
    this->data[i] = other.data[i];
  }
}

StringCreaterPieceByPiece& StringCreaterPieceByPiece::operator=(const StringCreaterPieceByPiece& other) {
  if (this != &other) {
    delete[] this->data;
    this->capacity = other.capacity;
    this->data = new StringPiece[capacity];
    this->count = other.count;
    for (unsigned i = 0; i < this->count; i++) {
      this->data[i] = other.data[i];
    }
  }
  return *this;
}

StringCreaterPieceByPiece::StringCreaterPieceByPiece(StringCreaterPieceByPiece&& other) noexcept {
  this->data = other.data;
  this->capacity = other.capacity;
  this->count = other.count;

  other.data = nullptr;
  other.capacity = 0;
  other.count = 0;
}

void StringCreaterPieceByPiece::addPiece(const char* value) {
  if (this->count >= this->capacity) resize(this->capacity * 2);

  StringPiece newPiece(value);

  this->data[this->count++] = newPiece;
}

void StringCreaterPieceByPiece::addPiece() {
  if (this->count >= this->capacity) resize(this->capacity * 2);

  StringPiece newPiece;

  this->data[this->count++] = newPiece;
}

void StringCreaterPieceByPiece::addPiece(const char* value, size_t index) {
  if (index >= this->capacity) return;

  StringPiece newPiece(value);
  this->data[index] = newPiece;

  if (index >= this->count) this->count = index+1;
}

MyString StringCreaterPieceByPiece::getString() const {
  char* fullString = nullptr;

  for (unsigned i = 0; i < this->count; i++) {
    const char* test = this->data[i].get();
    if( strlen(this->data[i].get()) ) {
      if (!fullString) {
        fullString = new char[strlen(this->data[i].get())+1];
        strcpy(fullString, this->data[i].get());
      } else {
        strcat(fullString, this->data[i].get());
      }
    } else {
      if (!fullString) {
        fullString = new char[21];
        strcpy(fullString, "                    ");
      } else {
        strcat(fullString, "                    ");
      }
    }
  }

  MyString res(fullString);
  return res;
}

StringPiece& StringCreaterPieceByPiece::operator[](size_t index) {
    return this->data[index];
}

void StringCreaterPieceByPiece::remove(size_t index) {
    if (index >= this->count) return;

    StringPiece newPiece;
    this->data[index] = newPiece;
  }

void StringCreaterPieceByPiece::swap(size_t index1, size_t index2) {
    if (index1 >= this->count || index2 >= this->count) return;

    StringPiece temp1(this->data[index1].get());
    StringPiece temp2(this->data[index2].get());

    this->data[index1] = temp2;
    this->data[index2] = temp1;
}

size_t StringCreaterPieceByPiece::size() {
    MyString str = this->getString();
    return str.size();
}

void StringCreaterPieceByPiece::resize(size_t newCapacity) {
  StringPiece* newData = new StringPiece[newCapacity];
  for (unsigned i = 0; i < this->count; i++) {
    newData[i] = this->data[i];
  }

  delete[] data;
  this->data = newData;
  this->capacity = newCapacity;
}
