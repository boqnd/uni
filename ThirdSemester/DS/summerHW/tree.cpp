#pragma once

#include <string>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include "node.cpp"

class tree {
private:
  node* root;
public:
  tree();
  tree(node* n);
  ~tree();

  node* getRoot();
  void setRoot(node*);
  std::string toString();

  tree load();
};

tree::tree(node* r) : root(r) {}

tree::tree() : root(nullptr) {}

tree::~tree(){
  root = nullptr;
}

node* tree::getRoot() {
  return this->root;
}

void tree::setRoot(node* r) {
  this->root = r;
}

std::string stringHelper(std::queue<std::vector<node*>>& current, std::queue<std::vector<node*>>& next) {

  std::string res = "";

  while (!current.empty())
  {
    std::vector<node*> brotherhood = current.front();

    for (node* n : brotherhood) {
      res += n->childrenToString();
      next.push(n->getChildren());
    }

    current.pop();
  }

  if(!next.empty()) { res += "|\n"; }

  return res;
}

std::string tree::toString() {
  if(!root) {
    return "| |";
  }

  std::string res = "";

  node helper;
  helper.addChild(root);

  res += helper.childrenToString();
  res += "|\n";

  std::queue<std::vector<node*>> q;
  std::queue<std::vector<node*>> helperQ;

  q.push(helper.getChildren());

  while(!q.empty()) {
    res += stringHelper(q, helperQ);
    q = helperQ;

    while(!helperQ.empty()) {
      helperQ.pop();
    }
  }

  return res;
}

tree tree::load() {
  std::string filename = "tree.txt";
  tree t;

  if(filename != "")
  {
      std::ifstream in(filename);

      if(in.good())
      {
          std::queue<node*> q;
          std::queue<node*> next;
          node* current = nullptr;
          q.push(current);

          while(!in.eof())
          {
              std::string line;
              std::getline(in, line);
              std::istringstream iss(line);

              if(iss.good())
              {
                  while(!iss.eof())
                  {
                    if (!current) {

                    }

                    std::string w;
                    iss >> w;

                    if(w != "|") {
                      q.push(new node(std::stoi(w)));
                    } else {
                      while(!q.empty()){
                        current->addChild(q.front());
                        next.push(q.front());
                        q.pop();
                      }
                    }
                    std::cout << w;
                  }
              }
              // if(strcmp(w,"| |") == 0) {

              // }
              // queue q;
              // queue next;
              // while (q)
              //   q.
          }
      }
  }
}
