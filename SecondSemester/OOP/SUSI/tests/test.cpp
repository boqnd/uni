#include "../include/test.h"

//vector
TEST_CASE("Vector operator []") {
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  CHECK(v[0] == 1);
  CHECK(v[1] == 2);
  CHECK(v[2] == 3);
}

TEST_CASE("Vector push_back") {
  Vector<int> v;
  CHECK(v.getSize() == 0);
  v.push_back(1);
  CHECK(v.getSize() == 1);
  v.push_back(2);
  CHECK(v.getSize() == 2);
  v.push_back(3);
  CHECK(v.getSize() == 3);

  CHECK(v[0] == 1);
  CHECK(v[1] == 2);
  CHECK(v[2] == 3);
}

TEST_CASE("Vector pop_back") {
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.pop_back();
  CHECK(v.getSize() == 2);
  CHECK(v[0] == 1);
  CHECK(v[1] == 2);
  v.pop_back();
  CHECK(v.getSize() == 1);
  CHECK(v[0] == 1);
  v.pop_back();
  CHECK(v.getSize() == 0);
}

TEST_CASE("Vector pop_front") {
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.pop_front();
  CHECK(v.getSize() == 2);
  CHECK(v[0] == 2);
  CHECK(v[1] == 3);
  v.pop_front();
  CHECK(v.getSize() == 1);
  CHECK(v[0] == 3);
  v.pop_front();
  CHECK(v.getSize() == 0);
}

TEST_CASE("Vector destroy") {
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.destroy();
  CHECK(v.getSize() == 0);
}

TEST_CASE("Vector getSize") {
  Vector<int> v;
  CHECK(v.getSize() == 0);
  v.push_back(1);
  CHECK(v.getSize() == 1);
  v.push_back(2);
  CHECK(v.getSize() == 2);
  v.push_back(3);
  CHECK(v.getSize() == 3);
  v.pop_back();
  CHECK(v.getSize() == 2);
  v.pop_front();
  CHECK(v.getSize() == 1);
}

TEST_CASE("Vector delete_at") {
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.delete_at(1);

  CHECK(v[0] == 1);
  CHECK(v[1] == 3);
}

//string
TEST_CASE("String operator = const char*") {
  String s = "test";
  CHECK(s == "test");
  CHECK(s[0] == 't');
  CHECK(s[1] == 'e');
  CHECK(s[2] == 's');
  CHECK(s[3] == 't');
}

TEST_CASE("String operator ==") {
  String s = "test";
  String s1 = "test";
  String s2 = "testest";

  CHECK(s == "test");
  CHECK(s == s1);
  CHECK(!(s == s2));
}

TEST_CASE("String push_back") {
  String s = "test";
  int len = s.length();

  s.push_back('0');

  CHECK(s.length() == len+1);
  CHECK(s == "test0");
  CHECK(s[0] == 't');
  CHECK(s[1] == 'e');
  CHECK(s[2] == 's');
  CHECK(s[3] == 't');
  CHECK(s[4] == '0');
}

TEST_CASE("String parseInt") {
  String s = "123";
  int num = s.parseInt();

  CHECK(num == 123);
  CHECK(s == "123");
}

TEST_CASE("String parseDouble") {
  String s = "123.2";
  double num = s.parseDouble();

  CHECK(num == 123.2);
  CHECK(s == "123.2");
}

TEST_CASE("String split") {
  String s = "t e s t test";
  Vector<String> spl = s.split(' ');

  CHECK(spl[0] == "t");
  CHECK(spl[1] == "e");
  CHECK(spl[2] == "s");
  CHECK(spl[3] == "t");
  CHECK(spl[4] == "test");
  CHECK(spl.getSize() == 5);

  CHECK(s == "t e s t test");
}

TEST_CASE("String getData") {
  String s = "test";
  char* d = s.getData();

  CHECK(!strcmp(d, "test"));
}

//discipline
TEST_CASE("Discipline getters and setters") {
  Discipline d;
  d.setName("test");
  d.setRequired(true);
  d.setYear(1);

  CHECK(d.getName() == "test");
  CHECK(d.isRequired() == true);
  CHECK(d.getYear() == 1);
}

//program
TEST_CASE("Program getters and setters") {
  Program p;
  String name = "program";
  Discipline d;
  d.setName("discipline");
  Vector<Discipline*> ds;
  ds.push_back(&d);

  p.setName(name);
  p.setDisciplines(ds);

  CHECK(p.getName() == name);
  CHECK(p.getDisciplines().getSize() == ds.getSize());
  CHECK(p.getDisciplines()[0]->getName() == d.getName());
}

TEST_CASE("Program addDiscipline") {
  Program p;
  Discipline d;
  d.setName("discipline");
  Vector<Discipline*> ds;

  p.addDiscipline(&d);

  CHECK(p.getDisciplines().getSize() == ds.getSize()+1);
  CHECK(p.getDisciplines()[0]->getName() == d.getName());
}

//student
TEST_CASE("Student getters and setters") {
  Student s;
  String stN = "testName";
  Program p;
  String prN = "program";
  p.setName(prN);

  s.setName(stN);
  s.setFn(123);
  s.setProgram(&p);
  s.setGroup(1);
  s.setYear(1);
  s.setStatus(Enrolled);
  s.setAverageGrade(0);

  CHECK(s.getName() == stN);
  CHECK(s.getFn() == 123);
  CHECK(s.getProgram()->getName() == prN);
  CHECK(s.getGroup() == 1);
  CHECK(s.getYear() == 1);
  CHECK(s.getStatus() == Enrolled);
  CHECK(s.getAverageGrade() == 0);
}

TEST_CASE("Student enroll") {
  Student s;
  String stN = "testName";
  Program p;
  String prN = "program";
  p.setName(prN);

  s.setName(stN);
  s.enroll(123, &p, 1);

  CHECK(s.getName() == stN);
  CHECK(s.getFn() == 123);
  CHECK(s.getProgram()->getName() == prN);
  CHECK(s.getGroup() == 1);
  CHECK(s.getYear() == 1);
  CHECK(s.getStatus() == Enrolled);
  CHECK(s.getAverageGrade() == 0);
}

TEST_CASE("Student advance") {
  Student s;
  String stN = "testName";
  Program p;
  String prN = "program";
  p.setName(prN);

  s.setName(stN);
  s.enroll(123, &p, 1);
  s.advance();

  CHECK(s.getName() == stN);
  CHECK(s.getFn() == 123);
  CHECK(s.getProgram()->getName() == prN);
  CHECK(s.getGroup() == 1);
  CHECK(s.getYear() == 2);
  CHECK(s.getStatus() == Enrolled);
  CHECK(s.getAverageGrade() == 0);
}

TEST_CASE("Student graduate") {
  Student s;
  String stN = "testName";
  Program p;
  String prN = "program";
  p.setName(prN);

  s.setName(stN);
  s.enroll(123, &p, 1);
  s.graduate();

  CHECK(s.getName() == stN);
  CHECK(s.getFn() == 123);
  CHECK(s.getProgram()->getName() == prN);
  CHECK(s.getGroup() == 1);
  CHECK(s.getYear() == 1);
  CHECK(s.getStatus() == Gradueted);
  CHECK(s.getAverageGrade() == 0);
}

TEST_CASE("Student interrupt") {
  Student s;
  String stN = "testName";
  Program p;
  String prN = "program";
  p.setName(prN);

  s.setName(stN);
  s.enroll(123, &p, 1);
  s.interrupt();

  CHECK(s.getName() == stN);
  CHECK(s.getFn() == 123);
  CHECK(s.getProgram()->getName() == prN);
  CHECK(s.getGroup() == 1);
  CHECK(s.getYear() == 1);
  CHECK(s.getStatus() == Interupted);
  CHECK(s.getAverageGrade() == 0);
}

TEST_CASE("Student resume") {
  Student s;
  String stN = "testName";
  Program p;
  String prN = "program";
  p.setName(prN);

  s.setName(stN);
  s.enroll(123, &p, 1);
  s.interrupt();
  s.resume();

  CHECK(s.getName() == stN);
  CHECK(s.getFn() == 123);
  CHECK(s.getProgram()->getName() == prN);
  CHECK(s.getGroup() == 1);
  CHECK(s.getYear() == 1);
  CHECK(s.getStatus() == Enrolled);
  CHECK(s.getAverageGrade() == 0);
}

//record
TEST_CASE("Record getters and setters") {
  Record r;
  Student s;
  String stN = "testName";
  s.setName(stN);
  Discipline d;
  d.setName("test");

  r.setStudent(&s);
  r.setDiscipline(&d);
  r.setGrade(6);

  CHECK(r.getStudent()->getName() == stN);
  CHECK(r.getDiscipline()->getName() == "test");
  CHECK(r.getGrade() == 6);
}

void runTests() {
  doctest::Context().run();
}

int main() {
  runTests();
  return 0;
}