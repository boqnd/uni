#include "sso.h"

SSO::SSO() : is_short(true), length(0) {
  this->short_str[0] = '\0';
  long_str = nullptr;
}

SSO::SSO(const char* str) : SSO() {
  this->assign(str);
}

SSO::~SSO() {
  delete[] long_str;
  long_str = nullptr;
}

SSO::SSO(const SSO& other) : SSO() {
  this->assign(other.getString());
}

SSO& SSO::operator=(const SSO& other) {
  if (this != &other) {
    this->assign(other.getString());
  }
  return *this;
}

SSO::SSO(SSO&& other) noexcept : is_short(other.is_short), length(other.length) {
  if (this->is_short) {
    memcpy(this->short_str, other.short_str, this->length + 1);
    other.short_str[0] = '\0';
  } else {
    this->long_str = other.long_str;
    other.long_str = nullptr;
  }
  other.length = 0;
  other.is_short = true;
}

const char* SSO::getString() const {
  return this->is_short ? this->short_str : this->long_str;
}

std::ostream& operator<<(std::ostream& os, const SSO& str) {
  return os << str.getString();
}

size_t SSO::size() const {
  return length;
}

void SSO::assign(const char* str) {
  size_t len = strlen(str);
  if (len <= this->capacity) {
    memcpy(this->short_str, str, len + 1);
    this->is_short = true;
  } else {
    char* current_long = new char[len + 1];
    memcpy(current_long, str, len + 1);
    delete[] this->long_str;
    this->long_str = current_long;
    this->is_short = false;
  }
  this->length = len;
}