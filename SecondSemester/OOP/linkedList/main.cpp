#include <iostream>
#include <fstream>
#include "linkedList.cpp"


int main() {

  LinkedList<int> ls;
  ls.push(1);
  ls.push(2);
  ls.push(3);
  ls.push(4);
  ls.push(5);
  ls.push(6);
  ls.push(7);
  ls.print();
  std::cout << "size: " << ls.size() << std::endl << std::endl;


  LinkedList<int> ls1(ls);
  ls1.push(8);
  ls1.push_back(0);
  ls1.print();
  std::cout << "size: " << ls1.size() << std::endl << std::endl;


  LinkedList<int> ls2(ls1);
  ls2.pop();
  ls2.pop_back();
  ls2.print();
  std::cout << "empty: " << std::boolalpha << ls2.empty() << std::endl << std::endl;


  LinkedList<int> ls3;
  ls3.push(1);
  ls3.push(2);
  ls3.pop();
  ls3.pop_back();
  ls3.print();
  std::cout << "empty: " << std::boolalpha << ls3.empty() << std::endl << std::endl;


  LinkedList<int> ls4(ls);
  ls4.clear();
  ls4.print();
  std::cout << "size: " << ls4.size() << std::endl << std::endl;

  LinkedList<int> ls5(ls);
  ls5.print();
  std::cout << "front: " << ls5.front()->data << ", back: " << ls5.back()->data << std::endl << std::endl;


  LinkedList<int> ls6;
  ls6.push_back(1);
  ls6.push_back(3);
  ls6.push_back(4);
  ls6.insertAfter(2,0);
  ls6.print();
  ls6.insertAfter(9,9);

  LinkedList<int> ls7(ls6);
  ls7.deleteAt(0);
  ls7.deleteAt(1);
  ls7.print();
  ls7.deleteAt(2);

  LinkedList<int> ls8(ls5);
  ls8=ls7;
  ls8.print();
  ls5.print();

  std::cout << std::endl;

  LinkedList<int> ls9;
  ls9.push(7);
  ls9.push(1);
  ls9.push(6);
  ls9.push(1);
  ls9.push(2);
  ls9.push(6);
  ls9.push(2);
  ls9.push(7);
  ls9.push(3);
  ls9.push(3);
  ls9.push(6);
  ls9.push(3);
  ls9.push(2);
  ls9.push(6);

  
  ls9.print();
  ls9.removeDublicates();
  std::cout << "remove duplicates... "; 
  ls9.print();

  std::cout << std::endl;


  LinkedList<char> example;
  example.push_back('h');
  example.push_back('e');
  example.push_back('l');
  example.push_back('l');
  example.push_back('o');
  example.push_back(' ');
  example.push_back('w');
  example.push_back('o');
  example.push_back('r');
  example.push_back('l');
  example.push_back('d');
  example.push_back('!');
  example.print();
  example.removeDublicates();
  example.print();
  std::cout << "chak sega vidqh che sum razbral greshno kakvo se iska pri mahaneto na povtoreniqta." << std::endl
    << "ama go pisha toq linked list ot 3 chasa i me murzi da go opravqm" << std::endl;


  ls.save();
  ls1.save();
  ls2.save();
  ls3.save();
  ls4.save();
  ls5.save();
  ls6.save();
  ls7.save();
  ls8.save();
  ls9.save();


  Vector< LinkedList<int> > vector;

  loadLists(vector);

  std::cout << std::endl << std::endl << 
    "Deserealization..." << std::endl;


  for (size_t i = 0; i < vector.getSize(); i++)
  {
    vector[i].print();
  }
  


  return 0;
}