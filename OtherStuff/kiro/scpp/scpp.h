#pragma once
#include <cstring>
#include <iostream>

class StringPiece {
public:
    StringPiece();
    StringPiece(char* value);
    StringPiece(const char* value);
    StringPiece(const StringPiece& other);
    StringPiece& operator=(const StringPiece& other);
    StringPiece(StringPiece&& other) noexcept;
    const char* get() const;
    void set(const char* value);
    void operator<<(const char* value);
    friend void operator>>(const char* value, StringPiece& piece);
    StringPiece& remove_prefix(size_t k);
    StringPiece& remove_suffix(size_t k);
    char& operator[](int index);

private:
    void copy(char* value);
    void copy(const char* value);

    char data[17];
};

class MyString {
public:
    MyString();
    MyString(const char* str);
    ~MyString();
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    MyString(MyString&& other) noexcept;
    size_t size() const;
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

private:
    size_t count;
    char* data;
};

class StringCreaterPieceByPiece {
public:
  StringCreaterPieceByPiece();
  StringCreaterPieceByPiece(size_t _capacity);
  ~StringCreaterPieceByPiece();
  StringCreaterPieceByPiece(const StringCreaterPieceByPiece& other);
  StringCreaterPieceByPiece& operator=(const StringCreaterPieceByPiece& other);
  StringCreaterPieceByPiece(StringCreaterPieceByPiece&& other) noexcept;
  void addPiece(const char* value);
  void addPiece();
  void addPiece(const char* value, size_t index);
  MyString getString() const;
  StringPiece& operator[](size_t index);
  void remove(size_t index);
  void swap(size_t index1, size_t index2);
  size_t size();
private:
  StringPiece* data;
  size_t capacity;
  size_t count;
  void resize(size_t newCapacity);
};