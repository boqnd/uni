#include <iostream>

class String {

private:
  char* data;

  void copy(const String&);
  void destroy();
  void setData(const char*);
  int length(const char*);

public:
  String();
  String(const String&);
  String(const char*);
  String& operator=(const String&);
  String& operator=(const char*);
  char operator[](const unsigned int);
  ~String();

  int length();

  friend std::ostream& operator<<(std::ostream& out, String&);
  friend std::istream& operator>>(std::istream& in, String& str);
};