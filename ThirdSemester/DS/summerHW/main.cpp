#include <iostream>
#include "tree.cpp"

int main() {

  // std::cout << 5;

  node* n = new node(8);
  // node* n2 = new node(3);
  // node* n3 = new node(2);
  // node* n4 = new node(9);
  // node* n5 = new node(2);
  // node* n6 = new node(8);
  // node* n7 = new node(6);
  // node* n8 = new node(2);
  // node* n31 = new node(8);
  // node* n41 = new node(6);
  // node* n51 = new node(11);
  // node* n61 = new node(12);
  // node* n71 = new node(8);
  // node* n81 = new node(5);
  // node* n141 = new node(11);
  // node* n151 = new node(4);
  // node* n161 = new node(3);
  // node* n171 = new node(11);
  // node* n181 = new node(6);

  // n->addChild(n2);
  // n->addChild(n3);
  // n->addChild(n4);

  // n2->addChild(n5);
  // n3->addChild(n6);
  // n3->addChild(n7);
  // n4->addChild(n8);

  // n5->addChild(n31);
  // n5->addChild(n41);
  // n6->addChild(n51);
  // n7->addChild(n61);
  // n8->addChild(n71);
  // n8->addChild(n81);

  // n31->addChild(n141);
  // n41->addChild(n151);
  // n41->addChild(n161);
  // n71->addChild(n171);
  // n81->addChild(n181);


  tree t;

  t.load();

  std::cout << t.toString();

  return 0;
}