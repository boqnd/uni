#include "implementation.cpp"
#include <fstream>
#include <iostream>

int main (int argc, char* argv[]) {
  std::ifstream file;
  std::ifstream file2;
  file.open(argv[1]);
  file2.open(argv[2]);

  Comparator comparator;

  ComparisonReport h1 = comparator.compare(file, file2);

  comparator.printReport(h1);
}