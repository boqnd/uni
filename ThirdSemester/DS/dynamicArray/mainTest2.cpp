#include <iostream>
#include <stdexcept>

class DArray{
  public:
    int* data;
    int size;
    int capacity;

    DArray(int capacity = 5) {
      this->capacity = capacity;
      this->size = 0;
      this->data = new int[capacity];
    }

    void resize() {
      throw std::invalid_argument("resize not implemented;");
    }

    void push_back(int& el) {
      if (this->size == this->capacity) {
        this->resize();
      }

      this->data[size++] = el;
    }

    void print() {
      std::cout << "< ";

      for (size_t i = 0; i < this->size; i++)
      {
        std::cout << this->data[i] << " ";
      }

      std::cout << ">" << std::endl;
    }
};

int main() {
  DArray da;
  int value1 = 1, value2 = 2, value3 = 3;
  int* a = &value1;
  int* b = &value2;
  int* c = &value3;

  da.push_back(a);
  da.push_back(b);
  da.push_back(c);

  da.print();


  int nvalue1 = 111, nvalue2 = 222, nvalue3 = 333;
  *a = nvalue1;
  *b = nvalue2;
  *c = nvalue3;

  da.print();
  return 0;
}