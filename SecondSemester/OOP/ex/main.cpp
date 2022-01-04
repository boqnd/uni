#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

class Entry {
protected:
  std::string _name;

public:
  virtual unsigned int size() = 0;
  virtual bool contains(const std::string& s) = 0; 
  std::string name() {
    return this->_name;
  };

  void setName(const std::string& s) {
    this->_name = s;
  }
  virtual std::string type() = 0;
  virtual void printContaining(const std::string& s) = 0;
  virtual void saveToFile(const char* fileName, int indent) = 0;

};

class Note : public Entry {
private:
  std::string data;

public:
  unsigned int size() {
    return this->data.size();
  }

  bool contains(const std::string& s) {
    return (this->data.find(s) < this->size());
  }

  void setData(const std::string& s) {
    this->data=s;
  }

  std::string type() {
    return "note";
  }

  void printContaining(const std::string& s) {
    std::cout << "the file " << this->name() << " is a note. Can not print containing." << std::endl;
  }

  void saveToFile(const char* fileName, int indent) {
    std::ofstream out (fileName, std::ofstream::app);
    
    for (size_t i = 0; i < indent; i++)
    {
      out << "-";
    }

    out << this->name() << std::endl;

    out.close();
  }

  
};

class Directory : public Entry {
private:
  std::vector<Entry*> data;

public:
  unsigned int size() {
    unsigned int result = 0;

    for (size_t i = 0; i < data.size(); i++)
    {
      result += data[i]->size();
    }
    
    return result;
  }

  bool contains(const std::string& s) {

    for (size_t i = 0; i < data.size(); i++)
    {
      if (data[i]->contains(s))
      {
        return true;
      }
    }

    return false;
  }

  void addEntry(Entry* e) {
    data.push_back(e);
  }

  std::string type() {
    return "dir";
  }

  void printContaining(const std::string& s) {
    for (size_t i = 0; i < data.size(); i++)
    {
      if (data[i]->type() == "note") {
        if (data[i]->contains(s))
        {
          std::cout << "file: " << data[i]->name() << "; file size: " << this->size() << std::endl;
        }
      } else if (data[i]->type() == "dir") {
        data[i]->printContaining(s);
      }
    }
  }
  void save(const char* fileName) {
    std::ofstream out (fileName);
    out.close();
    this->saveToFile(fileName,0);

  }

  void saveToFile(const char* fileName, int indent) {
    std::ofstream out (fileName, std::ofstream::app);
    
    for (size_t i = 0; i < indent; i++)
    {
      out << "-";
    }

    out << this->name() << std::endl;
    
    for (size_t i = 0; i < this->data.size(); i++)
    {
      out.close();
      data[i]->saveToFile(fileName, indent+1);
    }
  }
};



int main () {
  Directory root;
  Directory d;
  root.addEntry(&d);
  root.setName("root");
  d.setName("Dir");

  Directory d1;
  d.addEntry(&d1);
  d1.setName("subDir1");

  Note n;
  n.setData("text");
  n.setName("note1");
  d1.addEntry(&n);

  Note n1;
  n1.setData("lorem ipsum");
  n1.setName("note2");
  d.addEntry(&n1);


  // char s[64];
  // std::cout << "enter string for 4): ";
  // std::cin.getline(s, 64); 

  // root.printContaining(s);
  root.save("exam.txt");
  
}