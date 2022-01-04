#include "interface.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using std::string;
using std::vector;
using std::queue;
using std::stack;


void Hierarchy::fillData(const string& data) {
  string current = "";

  for (size_t i = 0; i < data.length(); i++)
  {
    if(data[i] != '\n') {
      if(data[i] != ' ') {
        current += data[i];
      }
    } else if (data[i] == '\n'){
      string boss = "";
      string who = "";
      bool flag = true;

      for (size_t j = 0; j < current.length(); j++) {
        if(current[j] != '-') {
          if (flag) {
            boss += current[j];
          } else {
            who += current[j];
          }
        } else {
          flag = false;
        }
      }
      if (this->data.getChild(boss) && who != "") {
        this->hire(who, boss);
      } else {
        throw std::runtime_error("error");
      }

      current = "";
    }
  }
  if (current != "") {
    string boss = "";
    string who = "";
    bool flag = true;

    for (size_t j = 0; j < current.length(); j++) {
      if(current[j] != '-') {
        if (flag) {
          boss += current[j];
        } else {
          who += current[j];
        }
      } else {
        flag = false;
      }
    }

    if (this->data.getChild(boss) && who != "") {
      this->hire(who, boss);
    } else {
      throw std::runtime_error("error");
    }
  }
}


Hierarchy::Hierarchy (Hierarchy&& r) noexcept {
  if(r.num_employees() > 0) {
    this->data.root = new node(r.data.root->value);
    this->names.push_back("Uspeshnia");
    this->fillData(r.print());
  }
}

Hierarchy::Hierarchy(const Hierarchy& r) {
  if(r.num_employees() > 0) {
    this->data.root = new node(r.data.root->value);
    this->names.push_back("Uspeshnia");
    this->fillData(r.print());
  }
}

Hierarchy::Hierarchy(const string& data) {
  if (data!="") {
    this->data.root = new node("Uspeshnia");
    this->names.push_back("Uspeshnia");
    this->fillData(data);
  }
}

Hierarchy::~Hierarchy() noexcept {}

string Hierarchy::print()const {
  string result = "";
  if(data.root) {
    vector<node*> resvec;
    vector<node*> resvec_;

    if (data.root) {
      queue<node*> q;
      q.push(this->data.root);

      while(!q.empty()) {
        // std::cout << "front " << q.front()->value << std::endl;
        for (size_t i = 0; i < q.front()->children.size(); i++)
        {
          resvec.push_back(q.front());
          resvec_.push_back(q.front()->children[i]); 
          // std::cout << q.front()->value<< "-" << q.front()->children[i]->value <<std::endl;


          // result += (q.front()->value + "-" + q.front()->children[i]->value + "\n");
          // q.push(q.front()->children[i]);
        }
        // std::cout << "while..." << std::endl;
        while (!resvec.empty())
        {
          // std::cout << "size:" << resvec.size() << std::endl;
          int index = 0;
          for (size_t i = 0; i < resvec.size(); i++)
          {
            // std::cout << resvec[i]->value+resvec_[i]->value << "?" << resvec[index]->value+resvec_[index]->value << std::endl;
            if ((resvec[i]->value+resvec_[i]->value) < (resvec[index]->value+resvec_[index]->value)) {
              index = i;
            }
          }

          result += resvec[index]->value + "-" + resvec_[index]->value + "\n";
          q.push(resvec_[index]);

          resvec.erase(resvec.begin() + index);
          resvec_.erase(resvec_.begin() + index);

        }

        q.pop();
      }
    }
  }

  return result;
}

int Hierarchy::longest_chain() const {
  if (names.size() == 0) {
    return 0;
  }
  
  int res = 0;
  for (size_t i = 0; i < this->names.size(); i++)
  {
    if (this->data.getLevel(this->names[i]) > res) {
      res = this->data.getLevel(this->names[i]);
    }
  }

  return res + 1;
}

bool Hierarchy::find(const string& name) const {
  return this->data.getChild(name);
}

int Hierarchy::num_employees() const {
  return this->names.size();
}

int Hierarchy::num_overloaded(int level) const {
  int result = 0;
  for (size_t i = 0; i < this->names.size(); i++)
  {
    if (numberOfSubChilds(this->data.getChild(this->names[i])) > level) {
      result++;
    }
  }

  return result;
}

string Hierarchy::manager(const string& name) const {
  return this->data.getParent(name) ? this->data.getParent(name)->value : "";
}

int Hierarchy::num_subordinates(const string& name) const {
  return this->data.getChild(name) ? this->data.getChild(name)->children.size() : -1;
}

unsigned long Hierarchy::getSalary(const string& who) const {
  return this->data.getChild(who) ? this->num_subordinates(who)*500 + (numberOfSubChilds(this->data.getChild(who))-this->num_subordinates(who))*50 : -1;
}

bool Hierarchy::fire(const string& who) {
  if (this->data.getChild(who) && who != data.root->value) {
    for (size_t i = 0; i < this->data.getChild(who)->children.size(); i++)
    {
      this->data.getParent(who)->children.push_back(this->data.getChild(who)->children[i]);
    }

    for (size_t i = 0; i < this->data.getParent(who)->children.size(); i++)
    {
      if (this->data.getParent(who)->children[i]->value == who) {
        this->data.getParent(who)->children.erase(this->data.getParent(who)->children.begin() + i);
        break;
      }
    }

    for (size_t i = 0; i < this->names.size(); i++)
    {
      if (this->names[i] == who) {
        this->names.erase(this->names.begin() + i);
        break;
      }
    }

    return true;
  } 
  return false;

}

bool Hierarchy::hire(const string& who, const string& boss) {
  if (this->data.getChild(boss))
  {
    if (!this->data.getChild(who)) {
      this->data.getChild(boss)->addCild(new node(who));
      this->names.push_back(who);
      return true;
    } else {
      node* parent = this->data.getParent(who);
      this->data.getChild(boss)->addCild(this->data.getChild(who));
      for (size_t i = 0; i < parent->children.size(); i++)
      {
        if (parent->children[i]->value == who) {
          parent->children.erase(parent->children.begin() + i);
        }
      }
      return true;
    }
  }
  return false;
}

void Hierarchy::incorporate() {
  if(data.root) {

    
    stack<string> st;

    queue<node*> q;
    q.push(data.root);
    st.push(data.root->value);

    while(!q.empty()) {
      
      for (size_t i = 0; i < q.front()->children.size(); i++)
      {
        st.push(q.front()->children[i]->value);
        q.push(q.front()->children[i]);
      }
      q.pop();
    }

    while(!st.empty()) {
      if (this->data.getChild(st.top())->children.size() >= 2) {
        string boss = "";

        for (size_t i = 0; i < this->data.getChild(st.top())->children.size(); i++)
        {
          if (this->getSalary(this->data.getChild(st.top())->children[i]->value) > (boss == "" ? 0 : this->getSalary(boss)) || (this->getSalary(this->data.getChild(st.top())->children[i]->value) == (boss == "" ? 0 : this->getSalary(boss)) && (this->data.getChild(st.top())->children[i]->value < boss || boss == ""))) {
            boss = this->data.getChild(st.top())->children[i]->value;
          }
        }
        // std::cout << boss << std::endl;

        queue<string> toRemove;
        for (size_t i = 0; i < this->data.getChild(st.top())->children.size(); i++)
        {
          if (this->data.getChild(st.top())->children[i]->value != boss)
          {
            this->data.getChild(boss)->addCild(this->data.getChild(st.top())->children[i]);
            toRemove.push(this->data.getChild(st.top())->children[i]->value);
          }
        }

        while(!toRemove.empty()) {
          for (size_t i = 0; i < this->data.getChild(st.top())->children.size(); i++)
          {
            if (this->data.getChild(st.top())->children[i]->value == toRemove.front())
            {
              this->data.getChild(st.top())->children.erase(this->data.getChild(st.top())->children.begin() + i);
              toRemove.pop();
              break;
            }
          }
        }
        
      }
      st.pop();
    }
  }
}

void Hierarchy::modernize() {
  stack<string> st;

  queue<node*> q;
  q.push(data.root);
  st.push(data.root->value);

  while(!q.empty()) {
    for (size_t i = 0; i < q.front()->children.size(); i++)
    {
      st.push(q.front()->children[i]->value);
      q.push(q.front()->children[i]);
    }
    q.pop();
  }

  while(!st.empty()) {
    if (this->data.getLevel(st.top()) % 2 != 0 && this->data.getChild(st.top())->children.size() > 0) {
      this->fire(st.top());
    }
    st.pop();
  }
}

Hierarchy Hierarchy::join(const Hierarchy& right) const {
  Hierarchy h("");

  h.data.root = new node("Uspeshnia");
  h.names.push_back("Uspeshnia");

  queue<string> s;
  s.push(this->data.root->value);

  while (!s.empty()) {
    if (this->data.getChild(s.front())) {
      for (size_t i = 0; i < this->data.getChild(s.front())->children.size(); i++)
      {
        if (!h.data.getChild(this->data.getChild(s.front())->children[i]->value)) {
          h.hire(this->data.getChild(s.front())->children[i]->value, s.front());
          s.push(this->data.getChild(s.front())->children[i]->value);
        }
      }
    }

    if (right.data.getChild(s.front())) {
      for (size_t i = 0; i < right.data.getChild(s.front())->children.size(); i++)
      {
        if (!h.data.getChild(right.data.getChild(s.front())->children[i]->value)) {
          h.hire(right.data.getChild(s.front())->children[i]->value, s.front());
          s.push(right.data.getChild(s.front())->children[i]->value);
        }
      }
    }
    
    s.pop();
  }

  return h;
}
