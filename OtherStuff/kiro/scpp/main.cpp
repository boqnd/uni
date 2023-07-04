#include <iostream>
#include "scpp.cpp"
#include <cstring>

using namespace std;

int main() {
  // StringPiece s("12345678901234567890");
  // std::cout << s.get() << std::endl;
  // StringPiece s1(s);
  // std::cout << s1.get() << std::endl;
  // StringPiece s2 = s1;
  // std::cout << s2.get() << std::endl;

  // StringPiece s3(move(s));
  // std::cout << s3.get() << std::endl;
  // std::cout << s.get() << std::endl;

  // const char* a = s.get();

  // std::cout << a << std::endl;
  // std::cout << strlen(a) << std::endl;

  // s.remove_prefix(0);
  // s[5] = 'A';

  // const char* b = s.get();

  // std::cout << b << std::endl;
  // std::cout << strlen(b) << std::endl;

  // StringCreaterPieceByPiece s(3);
  // s.addPiece("kur ");
  // s.addPiece("penis ");
  // s.addPiece("ta6ak ");
  // s.addPiece("12345678901234567890");

  // s.addPiece("test ", 5);

  // s[4] << " kur ";

  // s.addPiece();

  // s.addPiece("test ", 9);
  // s.remove(3);

  // s.swap(1,3);

  // std::cout << s.getString() << std::endl;
  // std::cout << s.size() << std::endl;

  StringCreaterPieceByPiece sc (2);
  sc. addPiece("test");
  sc. addPiece() ;
  sc. addPiece("football");
  sc[1] << " friends ";
  " Hello " >> sc[1];
  "10" >> sc[2];

  MyString result1 = sc.getString (); // "test Hello friends 10football"
  std::cout << result1 << std::endl;

  sc.swap(1, 2);
  MyString result2 = sc.getString (); // "test10football Hello friends"
  std::cout << result2 << std::endl;

  sc.remove(1);
  MyString result3 = sc.getString () ; // "test10                 Hello friends"
  std::cout << result3 << std::endl;

  return 0;
}