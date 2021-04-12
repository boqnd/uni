#include <iostream>


template <typename T>
void filter(T*& data, unsigned int size, bool (*filter) (T)) {
  for (size_t i = 0; i < size; i++) {
    if ((*filter) (data[i])) {
      std::cout << data[i] << std::endl;
    }
  }
}

bool isEvenNumber (int n) {
  return (n % 2 == 0);
}

bool isOddNumber (int n) {
  return (n % 2 != 0);
}

int main () {
  int size = 9;
  int* numbers = new int[size];
  for (int i = 0; i < size; i++) {
    numbers[i] = i+1;
  }
  
  filter<int> (numbers,size,isEvenNumber);
  std::cout << std::endl;
  filter<int> (numbers,size,isOddNumber);
  std::cout << std::endl;
  filter<int> (numbers,size,[](int a) -> bool {return a <= 5;});

}