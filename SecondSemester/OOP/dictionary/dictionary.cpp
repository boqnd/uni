#include <iostream>
#include <cstring>


struct Record {
  char word[100];
  char description[500];

  bool operator>(Record other) {
    return strcasecmp(this->word, other.word) > 0;
  }
};

class Dictionary { 

  private:
  Record *words;
  unsigned int size;

  public:
  Dictionary();
  void insert(Record);
  void remove(char*);
  void getDefinition(char*);
  void print();
  void sort();
};

Dictionary::Dictionary() {
  words = nullptr;
  size = 0;
}

void Dictionary::insert(Record newWord) {
  std::cout << "->Inserting \"" << newWord.word << "\" into dictionary" << std::endl;

  Record *helper = new Record[this->size + 1];

  for (int i = 0; i < this->size; i++) {
    helper[i] = this->words[i];
  }
  helper[size] = newWord;

  this->words = new Record[++this->size];

  for (int i = 0; i < this->size; i++) {
    this->words[i] = helper[i];
  }
}

void Dictionary::remove(char *word) {
  std::cout << "->Removing \"" << word << "\" from dictionary..." << std::endl;

  bool flag = true;
  for (int j = 0; j < this->size; j++) {
    if (strcmp(this->words[j].word,word) == 0) {
      Record *helper = new Record[this->size - 1];

      for (int i = 0; i < this->size; i++) {
        if (i < j) {
          helper[i] = this->words[i];
        }else if (i > j) {
          helper[i-1] = this->words[i];
        }
      }

      this->words = new Record[--this->size];

      for (int i = 0; i < this->size; i++) {
        this->words[i] = helper[i];
      }
      
      flag = false;
      break;
    }
  }

  if (flag) {
    std::cout << " ->No word was removed." << std::endl;
    std::cout << "  ->The dictionary does not contain word \"" << word << "\"" << std::endl;
  }
}

void Dictionary::getDefinition(char *word) {
  std::cout << "->Getting definition for \"" << word << "\"..." << std::endl;
  
  bool flag = true;
  for (int i = 0; i < this->size; i++) {
    if (strcmp(this->words[i].word,word) == 0) {
      std::cout << " -> ------------------------------------" << std::endl;
      std::cout << "      " << this->words[i].word << " - " <<
        this->words[i].description << std::endl;
      std::cout << "    ------------------------------------" << std::endl;
      flag = false;
      break;
    }
  }

  if (flag) {
    std::cout << " ->The dictionary does not contain word \"" << word << "\"" << std::endl;
  }
}

void Dictionary::print() {
  std::cout << "->Printing dictionary..." << std::endl << std::endl;
  std::cout << " -> ------------------------------------" << std::endl;

  for (int i = 0; i < this->size; i++) {
    std::cout << "      " << i+1 << ") " << this->words[i].word << " - " <<
     this->words[i].description << std::endl;
  }

  std::cout << "    ------------------------------------" << std::endl;
  std::cout << std::endl;
}

void Dictionary::sort() {
  std::cout << "->Sorting dictionary..." << std::endl;

  bool flag = true;
  while(flag) {
    flag = false;
    for (int i = 0; i < this->size - 1; i++) {
      if (this->words[i] > this->words[i+1]) {
        Record *helper = new Record[this->size];

        for (int k = 0; k < this->size; k++) {
          if (k == i) {
            helper[k] = this->words[k+1];
          }else if (k == i+1) {
            helper[k] = this->words[k-1];
          }else {
            helper[k] = this->words[k];
          }
        }

        this->words = new Record[this->size];

        for (int j = 0; j < this->size; j++) {
          this->words[j] = helper[j];
        }

        flag = true;
      }
    }
  }
}

int main() {
  Record r1 = {"geometriq", "trudno se vzima"};
  Record r2 = {"algebra", "trudno se vzima"};
  Record r3 = {"diskretni", "ne se vzima"};
  Record r4 = {"oop", "6te minem"};
  Record r5 = {"organizacionen kurs", "..."};

  Dictionary d;

  d.insert(r1);
  d.insert(r2);
  d.insert(r3);
  d.insert(r4);
  d.insert(r5);
  d.print();

  d.sort();
  d.print();

  d.getDefinition(r5.word);

  d.remove(r5.word);
  d.print();

  d.getDefinition(r5.word);
  d.remove(r5.word);

  return 0;
}