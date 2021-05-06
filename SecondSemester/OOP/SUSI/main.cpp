#include "include/index.h"

int main() {
  Program p;
  Discipline d;
  Discipline d1;

  d.setName("Algebra");
  d1.setName("Geometriq");

  Vector<Discipline> ds;
  ds.push_back(d);
  ds.push_back(d1);

  //std::cout << ds.getSize() << std::endl; 

  String progName = "IS";
  p.setName(progName);
  p.setDisciplines(ds);
  p.addDiscipline(d);
  Student st;
  Student std;
  String name = "Boba";
  st.setName(name);
  st.setFn(12345);
  st.setProgram(p);
  st.enroll(72029, p, 1);
  st.advance();
  st.interrupt();
  st.graduate();
  st.change("program", "kn");
  st.print();

  Record r;

  std.saveToFile("data/students.data");
  p.saveToFile("data/programs.data");
  d.saveToFile("data/disciplines.data");
  r.saveToFile("data/records.data");

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

