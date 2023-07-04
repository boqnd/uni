#include <iostream>
#include <cstring>
#include "sso.cpp"

using namespace std;

int main() {
  SSO s("abcdaasdfghjklasdfgh");

  std::cout << s << std::endl;
  std::cout << s.size() << std::endl;

  return 0;
}