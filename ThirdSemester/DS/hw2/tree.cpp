#pragma once
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;

struct node {
  string value;
  vector<node*> children;

  node(std::string val) {
    value = val;
  }
  
  void addCild(node *child) {
    children.push_back(child);
  }
};

class Tree {
  public:
    node *root;

    Tree() : root(nullptr){} 
    Tree(node* r) : root(r){} 

    ~Tree() { delete root; }

    node* getChild(string name) const {
      return getNode(root, name);
    }

    node* getParent(string name) const {
      return getParent_(root, nullptr, name);
    }

    int getLevel(string name) const {
      return getLevel_(root, name, 0);
    }

  private:
    node* getNode(node* node, string name) const {
      if (node == nullptr)
        return nullptr;
      else {
        if (node->value != name) {
          for (int i=0; i < node->children.size(); i++) {
            if (getNode(node->children[i], name)) {
              return getNode(node->children[i], name);
            }
          }
          return nullptr;
        } else {
          return node;
        }
      }
    }

    node* getParent_(node* node_, node* parent, string name) const {
      if (node_ == nullptr)
        return nullptr;
      else {
        if (node_->value != name) {
          for (int i=0; i < node_->children.size(); i++) {
            if (getParent_(node_->children[i], node_, name)) {
              return getParent_(node_->children[i], node_, name);
            }
          }
          return nullptr;
        } else {
          return parent;
        }
      }
    }

    int getLevel_(node* start, string name, int level) const {
      if (start == nullptr)
        return -1;
      else {
        if (start->value != name) {
          for (int i=0; i < start->children.size(); i++) {
            if (getLevel_(start->children[i], name, level+1) != -1) {
              return getLevel_(start->children[i], name, level+1);
            }
          }
          return -1;
        } else {
          return level;
        }
      }
    }
};

int numberOfSubChilds(node* node) {
  int result = 0;

  if (node != nullptr) {
    for (size_t i = 0; i < node->children.size(); i++)
    {
      result += 1 + numberOfSubChilds(node->children[i]);
    }
  }

  return result;
}
