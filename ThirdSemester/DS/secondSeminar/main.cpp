#include <iostream>
#include <typeinfo>

class Student {
  public:
    int fn;

    void displayFn() {
      std::cout << fn << std::endl;
    }

    Student() {
      fn = 123;
      std::cout << "Created" << std::endl;
    }

    ~Student() {
      fn = 0;
    }
};

/**
 * @param test
*/

int main() {

  Student* student = (Student *)(operator new(sizeof(Student)));

  new(student) Student();

  Student* stuP = (Student*)student; 
  
  stuP->~Student();
  operator delete(stuP);

  student->displayFn();
  stuP->displayFn();


  return 0;
}