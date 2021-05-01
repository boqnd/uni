#include <fstream>
#include <iostream>
#include <string>

void Reed() {
  std::ifstream input("test.txt", std::ifstream::in);
  std::string row = "";

  while(!input.eof()) {
    std::getline(input, row);

    std::cout << row << std::endl;
  }

  input.close();
}

void Write() {
  std::ofstream output("test.txt", std::fstream::app);

  output << "KurGolem" << std::endl;
  output.close();
}

int main () {
  Reed();
}