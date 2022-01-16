#pragma once
#include "interface.h"
#include <iostream>

WordCount::WordCount(string w, size_t c) : word(w), count(c){}

WordsMultiset::WordsMultiset() {
  this->capacity = 10;
  this->size = 0;
  this->containers = 0;
  this->table = new std::list<WordCount>[this->capacity];
}

WordsMultiset::WordsMultiset(size_t _capacity) {
  this->capacity = _capacity;
  this->size = 0;
  this->containers = 0; 
  this->table = new std::list<WordCount>[_capacity];
}

WordsMultiset::~WordsMultiset() {
  delete[] this->table;
}

void WordsMultiset::resize() {
  WordsMultiset* newSet = new WordsMultiset(this->capacity*2);
  
  for (size_t j = 0; j < this->capacity; j++)
  {
    for (list<WordCount>::iterator i = table[j].begin(); i != table[j].end(); i++)
    {
      newSet->add(i->word);
    }
  }

  this->table = newSet->table;
  this->size = newSet->size;
  this->capacity = newSet->capacity;
  this->containers = newSet->containers;
}

const size_t WordsMultiset::getHashIndex(const string& s) const {
  return (this->hash(s))%(this->capacity);
}

WordCount* WordsMultiset::find(const string& word) const {
  for (list<WordCount>::iterator i = table[getHashIndex(word)].begin(); i != table[getHashIndex(word)].end(); i++)
  {
    if (i->word == word) {
      return &(*i);
    }
  }
  return nullptr;
}

void WordsMultiset::print() const {
  for (size_t j = 0; j < this->capacity; j++)
  {
    std::cout << j << " ->";
    for (list<WordCount>::iterator i = table[j].begin(); i != table[j].end(); i++)
    {
      std::cout << " { " << i->word << "-" << i->count << " }";
    }
    std::cout << std::endl;
  }
}

void WordsMultiset::add(const std::string& word, size_t times) {
  for (list<WordCount>::iterator i = table[getHashIndex(word)].begin(); i != table[getHashIndex(word)].end(); i++)
  {
    if (i->word == word) {
      i->count += times;
      this->size += times;
      return;
    }
  }
  table[getHashIndex(word)].push_back(WordCount(word, times));
  this->size += times;
  this->containers++;

  if (this->containers > 0.7*capacity) {
    this->resize();
  }
}

bool WordsMultiset::contains(const std::string& word) const {
  return this->find(word);
}

size_t WordsMultiset::countOf(const std::string& word) const {
  WordCount* pair = this->find(word);
  return pair ? pair->count : 0;
}

ComparisonReport Comparator::compare(std::istream& a, std::istream& b) {
  WordsMultiset h1;
  WordsMultiset h2;
  
  string word;

  while (a >> word) {
    h1.add(word);
  }

  while (b >> word) {
    h2.add(word);
  }

  ComparisonReport report;

  for (size_t j = 0; j < h1.capacity; j++)
  {
    for (list<WordCount>::iterator i = h1.table[j].begin(); i != h1.table[j].end(); i++)
    {
      if (h2.contains(i->word)) {
        if (h2.countOf(i->word) < i->count) {
          report.commonWords.add(i->word, h2.countOf(i->word)); 
          report.uniqueWords[0].add(i->word, i->count - h2.countOf(i->word));
        } else if (h2.countOf(i->word) > i->count) { 
          report.commonWords.add(i->word, i->count);  
          report.uniqueWords[1].add(i->word, h2.countOf(i->word) - i->count);
        } else {
         report.commonWords.add(i->word, i->count);   
        }
      } else {
        report.uniqueWords[0].add(i->word, i->count); 
      }
    }
  }

  for (size_t j = 0; j < h2.capacity; j++)
  {
    for (list<WordCount>::iterator i = h2.table[j].begin(); i != h2.table[j].end(); i++)
    {
      if (!h1.contains(i->word)) {
        report.uniqueWords[1].add(i->word, i->count); 
      }
    }
  }

  return report;
}

size_t WordsMultiset::countOfUniqueWords() const {
  return this->containers;
};

std::multiset<std::string> WordsMultiset::words() const {
  std::multiset<std::string> set;
  for (size_t j = 0; j < this->capacity; j++)
  {
    for (list<WordCount>::iterator i = table[j].begin(); i != table[j].end(); i++)
    {
      for (int t = 0; t < i->count; t++) {
        set.insert(i->word);
      }
    }
  } 
  return set;
}

void Comparator::printReport(ComparisonReport& report) {
  double cw = report.commonWords.size, uw1 = report.uniqueWords[0].size, uw2 = report.uniqueWords[1].size;
  std::cout << "file1 -> file2 ( " << cw*(100/(cw+uw1)) << "% )" << std::endl;
  std::cout << "file2 -> file1 ( " << cw*(100/(cw+uw2)) << "% )" << std::endl;
};