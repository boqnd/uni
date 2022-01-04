#include <iostream>
#include <functional>

template <typename T>
class Monoid {
  private:
  T data;
  std::function<T(T)> func;

  public:
  Monoid(T _data, std::function<T(T)> _func) : data(_data), func(_func) {}

  T execute() {
    return func(data);
  }

  T getData() {
    return data;
  }
};

int Plus0(int n) {
  return n+0;
}

int main() {

  Monoid<int> m(3, Plus0);

  std::cout << std::boolalpha << (m.execute() == m.getData()) << std::endl; //f(единичен елемент) = единичен елемент ???

  //изобщо не разбрах условието...
  //надявам се че показвам че знам как се използва std::function .. от там нататък...
  return 0;
}