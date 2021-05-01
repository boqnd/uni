#include <iostream>

template <typename T>
struct TypedBuffer {
  T* data;
  unsigned int size;
};

template <typename T>
TypedBuffer<T> create(unsigned int n, T k) {
  TypedBuffer<T> buffer;
  buffer.size = n;
  buffer.data = new T[n];
  for (size_t i = 0; i < n; i++) {
    buffer.data[i] = k;
  }

  return buffer;
}

template <typename T>
void append(TypedBuffer<T>& a, TypedBuffer<T>& b) {
  TypedBuffer<T> temp;

  temp.size = a.size + b.size;
  temp.data = new T[a.size+b.size];
  
  for (size_t i = 0; i < a.size; i++) {
    temp.data[i] = a.data[i];
  }

  for (size_t i = 0; i < b.size; i++) {
    temp.data[a.size + i] = b.data[i];
  }

  a.size = temp.size;

  a.data = new T [temp.size];

  for (size_t i = 0; i < temp.size; i++)
  {
    a.data[i] = temp.data[i];
  }
}

template <typename T>
TypedBuffer<T> concat(TypedBuffer<T>& a, TypedBuffer<T>& b) {
  TypedBuffer<T> temp;

  temp.size = a.size + b.size;
  temp.data = new T[a.size+b.size];
  
  for (size_t i = 0; i < a.size; i++) {
    temp.data[i] = a.data[i];
  }

  for (size_t i = 0; i < b.size; i++) {
    temp.data[a.size + i] = b.data[i];
  }

  return temp;
}

template <typename T>
TypedBuffer<T> myUnion(TypedBuffer<T>& a, TypedBuffer<T>& b) {
  TypedBuffer<T> temp = concat(a, b);

  int* tempData = new int[temp.size];
  int tempSize = 0;

  for (size_t i = 0; i < temp.size; i++) {
    bool flag = true;
    for (size_t j = 0; j < tempSize; j++) {
      if(tempData[j] == temp.data[i]) flag = false;
    }
    
    if (flag)
    {
      tempData[tempSize] = temp.data[i];
      tempSize++;
    }
  }

  TypedBuffer<T> result;
  result.size = tempSize;
  result.data = new T[tempSize];

  for (size_t i = 0; i < tempSize; i++)
  {
    result.data[i] = tempData[i];
  }

  return result;
}

template <typename T>
void print(TypedBuffer<T>& a) {
  std::cout << "{";

  for (size_t i = 0; i < a.size; i++)
  {
    std::cout << " " << a.data[i] << " ";
  }

  std::cout << "}" << std::endl;
}




class SumAvgCalculator {
private:
  int* data;
  int size;

  void destroy() {
    delete[] data;
    size = 0;
  }

public:
  SumAvgCalculator(int a) {
    size = 1;
    data = new int[1];
    data[0] = a;
  }

  ~SumAvgCalculator() {
    destroy();
  }

  int sum() {
    int result = 0;
    for (size_t i = 0; i < this->size; i++)
    {
      result += this->data[i];
    }
    
    return result;
  }

  void add(int a) {
    int* temp = new int[this->size + 1];

    for (size_t i = 0; i < this->size; i++)
    {
      temp[i] = this->data[i];
    }

    temp[this->size] = a;
    
    delete[] this->data;

    this->size += 1;
    this->data = new int[this->size];

    for (size_t i = 0; i < this->size; i++)
    {
      this->data[i] = temp[i];
    }
  }

  void sub(unsigned a) {
    this->add(a*(-1));
  }

  int num() {
    return this->size;
  }

  double average() {
    return this->sum()/this->size;
  }

};



void testTask1() {
  std::cout << std::endl << std::endl << "TASK 1" << std::endl << "------" << std::endl;

  TypedBuffer<int> tb1 = create(5, 1);
  TypedBuffer<int> tb2 = create(3, 2);

  std::cout << "tb1: ";
  print(tb1);
  std::cout << "tb2: ";
  print(tb2);

  append(tb1,tb2);
  std::cout << "-> append tb1 & tb2" << std::endl;
  std::cout << "tb1: ";
  print(tb1);

  TypedBuffer<int> tb3 = concat(tb1, tb2);
  std::cout << "-> concat tb1 & tb2 into tb3" << std::endl;
  std::cout << "tb3: ";
  print(tb3);

  TypedBuffer<int> tb4 = myUnion(tb3, tb2);
  std::cout << "-> union tb3 & tb2 into tb4" << std::endl;
  std::cout << "tb4: ";
  print(tb4);
}

void testTask2() {
  std::cout << std::endl << std::endl << "TASK 2" << std::endl << "------" << std::endl;
  SumAvgCalculator seq (5);
  seq.add(5);
  seq.sub(2);
  seq.add(0);

  std::cout << "sum: " << seq.sum() << std::endl;
  std::cout << "average: " << seq.average() << std::endl;
}

int main() {
  testTask1();
  testTask2();

  return 0;
}

// create
// append
// concat
// union
