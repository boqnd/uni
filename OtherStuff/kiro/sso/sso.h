#pragma once
#include <cstring>
#include <iostream>

class SSO {
public:
  SSO();
  SSO(const char* str);
  ~SSO();
  SSO(const SSO& other);
  SSO& operator=(const SSO& other);
  SSO(SSO&& other) noexcept;
  const char* getString() const;
  friend std::ostream& operator<<(std::ostream& os, const SSO& str);
  size_t size() const;

private:
  static const size_t capacity = 15;
  bool is_short;
  size_t length;
  char short_str[capacity + 1];
  char* long_str;
  void assign(const char* str);
};