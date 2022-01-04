#include <iostream>
#include "String.h"

int main() {
  
  //exceptions added at rows: 153, 158, 165, 170, 189, 209

  String k = "ur";
  while (k != "end")
  {
    try
    {
      String n;
      std::cout << "enter word: ";
      std::cin >> k;
      std::cout << "enter an index smaller than the length of the word: ";
      std::cin >> n;
      std::cout << "the " << n << "-th index of the word \'" << k << "\' is \'" << k[n.parseInt()] << "\'." << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cout << "|    <error>    |" << std::endl << std::endl;

      std::cout << "exception: " << e.what() << std::endl << std::endl;
    }
  }

  return 0;
}