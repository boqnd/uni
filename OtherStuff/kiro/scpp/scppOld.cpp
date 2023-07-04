#include <cstring>
#include <iostream>

class StringPiece {
public:
  StringPiece() {
    this->data[0] = '\0';
  }

  StringPiece(char* value) {
    this->copy(value);
  }

  StringPiece(const char* value) {
    this->copy(value);
  }

  StringPiece(const StringPiece& other) {
    this->copy(other.data);
  }

  StringPiece& operator=(const StringPiece& other) {
    if (this != &other) {
      this->copy(other.data);
    }
    return *this;
  }

  StringPiece(StringPiece&& other) noexcept {
    memcpy(data, other.data, sizeof(data));
    other.data[0] = '\0';
  }

  const char* get() const {
    return this->data;
  }

  void set(const char* value) {
    this->copy(value);
  }

  void operator<<(const char* value) {
    size_t len = strlen(this->data) + strlen(value);

    char* concat = new char[len + 1];
    strncpy(concat, this->data, 16);

    strcat(concat, value);

    this->copy(concat);
  }

  friend void operator>>(const char* value, StringPiece& piece) {
    size_t len = strlen(piece.data) + strlen(value);

    char* concat = new char[len + 1];
    strncpy(concat, value, 16);

    strcat(concat, piece.data);

    piece.set(concat);
    delete[] concat;
  }

  StringPiece& remove_prefix(size_t k) {
    k = k < 16 ? k : 16;

    memmove(this->data, this->data + k, sizeof(this->data) - k);
    memset(this->data + sizeof(this->data) - k, '\0', k);
    return *this;
  }

  StringPiece& remove_suffix(size_t k) {
    k = k < 16 ? k+1 : 17;

    memset(this->data + sizeof(this->data) - k, '\0', k);
    return *this;
  }

  char& operator[](int index) {
    return this->data[index];
  }

private:
  void copy(char* value) {
    strncpy(this->data, value, 16);
  }

  void copy(const char* value) {
    strncpy(this->data, value, 16);
  }

  char data[17];
};

class MyString {
public:
    MyString() : count(0), data(nullptr) {}

    MyString(const char* str) : count(strlen(str)), data(new char[this->count + 1]) {
      strcpy(this->data, str);
    }

    ~MyString() {
      delete[] this->data;
      this->data = nullptr;
    }

    MyString(const MyString& other) : count(other.count), data(new char[this->count + 1]) {
      strcpy(this->data, other.data);
    }

    MyString& operator=(const MyString& other) {
      if (this != &other) {
        delete[] this->data;
        this->count = other.count;
        this->data = new char[this->count + 1];
        strcpy(this->data, other.data);
      }
      return *this;
    }

    MyString(MyString&& other) noexcept : count(other.count), data(other.data) {
      other.count = 0;
      other.data = nullptr;
    }

    size_t size() const {
      return this->count;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
      return os << str.data;
    }

private:
    size_t count;
    char* data;
};

class StringCreaterPieceByPiece {
public:
  StringCreaterPieceByPiece() {
    this->capacity = 0;
    this->data = nullptr;
    this->count = 0;
  }

  StringCreaterPieceByPiece(size_t _capacity) {
    this->capacity = _capacity;
    this->data = new StringPiece[capacity];
    this->count = 0;
  }

  ~StringCreaterPieceByPiece() {
    delete[] this->data;
    this->data = nullptr;
    this->count = 0;
    this->capacity = 0;
  }

  StringCreaterPieceByPiece(const StringCreaterPieceByPiece& other) {
    this->capacity = other.capacity;
    this->data = new StringPiece[capacity];
    this->count = other.count;
    for (unsigned i = 0; i < this->count; i++) {
      this->data[i] = other.data[i];
    }
  }

  StringCreaterPieceByPiece& operator=(const StringCreaterPieceByPiece& other) {
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

  StringCreaterPieceByPiece(StringCreaterPieceByPiece&& other) noexcept {
    this->data = other.data;
    this->capacity = other.capacity;
    this->count = other.count;

    other.data = nullptr;
    other.capacity = 0;
    other.count = 0;
  }

  void addPiece(const char* value) {
    if (this->count >= this->capacity) resize(this->capacity * 2);

    StringPiece newPiece(value);

    this->data[this->count++] = newPiece;
  }

  void addPiece() {
    if (this->count >= this->capacity) resize(this->capacity * 2);

    StringPiece newPiece;

    this->data[this->count++] = newPiece;
  }

  void addPiece(const char* value, size_t index) {
    if (index >= this->capacity) return;

    StringPiece newPiece(value);
    this->data[index] = newPiece;

    if (index >= this->count) this->count = index+1;
  }

  MyString getString() const {
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

  StringPiece& operator[](size_t index) {
    return this->data[index];
  }

  void remove(size_t index) {
    if (index >= this->count) return;

    StringPiece newPiece;
    this->data[index] = newPiece;
  }

  void swap(size_t index1, size_t index2) {
    if (index1 >= this->count || index2 >= this->count) return;

    StringPiece temp1(this->data[index1].get());
    StringPiece temp2(this->data[index2].get());

    this->data[index1] = temp2;
    this->data[index2] = temp1;
  }

  size_t size() {
    MyString str = this->getString();
    return str.size();
  }

private:
  StringPiece* data;
  size_t capacity;
  size_t count;

  void resize(size_t newCapacity) {
    StringPiece* newData = new StringPiece[newCapacity];
    for (unsigned i = 0; i < this->count; i++) {
      newData[i] = this->data[i];
    }

    delete[] data;
    this->data = newData;
    this->capacity = newCapacity;
  }
};