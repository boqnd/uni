#include <vector>
#include <string>

class node {
private:
  int value;
  std::vector<node*> children;
public:
  node();
  ~node();
  node(const node&);
  node(int);
  int getValue();
  std::vector<node*> getChildren();
  void setValue(int);
  void setChildren(std::vector<node*>);

  void addChild(node*);

  std::string toString();
  std::string childrenToString();

};

node::node(){}

node::~node(){}

node::node(int val) {
  this->value = val;
}

int node::getValue() {
  return this->value;
}

std::vector<node*> node::getChildren() {
  return this->children;
}

void node::setValue(int value_) {
  this->value = value_;
}

void node::setChildren(std::vector<node*> children_) {
  this->children = children_;
}

void node::addChild(node* child) {
  this->children.push_back(child);
}

std::string node::toString() {
  std::string res = " ";
  res += std::to_string(this->value);

  return res;
}

std::string node::childrenToString() {
  std::string res = "|";

  for (node* n : this->children) {
    res += n->toString();
  }

  res += " ";

  return res;
}