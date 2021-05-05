#include "include/index.h"

int main() {

  Program p;
  Discipline d;
  Discipline d1;

  Vector<Discipline> ds;
  ds.push_back(d);
  ds.push_back(d1);

  std::cout << ds.getSize() << std::endl; 

  String progName = "IS";
  p.setName(progName);

  Student st;
  String name = "Boba";
  st.setName(name);
  st.setFn(12345);
  st.setProgram(p);
  st.enroll(72029, p, 1);
  st.advance();
  st.interrupt();
  st.graduate();
  st.print();
  //st.enroll(72029, "IS", 1)
    // .print()
    // .interrupt()
    // .print()
    // .resume()
    // .advance()
    // .graduate()
    //.print();
  
  return 0;
}

