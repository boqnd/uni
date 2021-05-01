#pragma once
#include "linkedList.h"
#include "Vector.h"
#include <iostream>


template <typename T>
LinkedList<T>::LinkedList() {
  this->first = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
  this->first = nullptr;

  if (other.front() != nullptr)
  {
    this->first = new Node<T>(other.front()->data, nullptr);
    Node<T>* current = other.front()->next;
    Node<T>* thisCurrent = this->front();

    while (current != nullptr)
    {
      thisCurrent->next = new Node<T>(current->data, nullptr);
      thisCurrent = thisCurrent->next;
      current = current->next;
    }
  }
}

template <typename T>
LinkedList<T>::~LinkedList() {
  this->clear();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& other) {
  this->first = nullptr;

  if (other.front() != nullptr)
  {
    this->first = new Node<T>(other.front()->data, nullptr);
    Node<T>* current = other.front()->next;
    Node<T>* thisCurrent = this->front();

    while (current != nullptr)
    {
      thisCurrent->next = new Node<T>(current->data, nullptr);
      thisCurrent = thisCurrent->next;
      current = current->next;
    }
  }

  return *this;
}

template <typename T>
void LinkedList<T>::print() const {
  Node<T>* current = this->front();

  std::cout << '[';
  while (current != nullptr)
  {
    std::cout << current->data;

    if (current->next != nullptr)
    {
      std::cout << " -> ";
    }
    
    current = current->next;
  }

  std::cout << ']' << std::endl;

}

template <typename T>
void LinkedList<T>::push(const T& data) {
  Node<T>* newNode = new Node<T>(data, this->first);
  this->first = newNode;
}

template <typename T>
void LinkedList<T>::push_back(const T& data) {
  Node<T>* current = this->front();
  Node<T>* newNode = new Node<T>(data, nullptr);
  
  if (current != nullptr) {
    while (current->next != nullptr)
    {
      current = current->next;
    }

    current->next = newNode;
  } else {
    this->first = newNode;
  }
}

template <typename T>
void LinkedList<T>::pop() {
  if (this->first != nullptr)
  {
    this->first = this->first->next;
  }
}

template <typename T>
void LinkedList<T>::pop_back() {
  Node<T>* current = this->front();
  
  if (current != nullptr) {
    if (current -> next == nullptr)
    {
      this->first = nullptr;
    }else {
      while (current->next->next != nullptr)
      {
        current = current->next;
      }
      current->next = nullptr;
    }
  }
}

template <typename T>
void LinkedList<T>::clear() {
  int size = this->size();
  for (size_t i = 0; i < size; i++)
  {
    this->pop();
  }
}

template <typename T>
void LinkedList<T>::insertAfter(const T& data, const unsigned int& index) {
  Node<T>* current = this->front();
  
  if (index < this->size()) {
    for (size_t i = 0; i < index; i++)
    {
      current = current->next;
    }
    
    Node<T>* newNode = new Node<T>(data, current->next);
    current->next = newNode;
  } else {
    std::cout << "Index out of boundry" << std::endl << std::endl;
  }
}

template <typename T>
void LinkedList<T>::deleteAt(const unsigned int& index) {
  Node<T>* current = this->front();
  
  if (index < this->size()) {
    if (index == 0)
    {
      this->pop();
    } else {
      for (size_t i = 0; i < index-1; i++)
      {
        current = current->next;
      }
      
      Node<T>* toDelete = current->next;

      current->next = toDelete->next;

      toDelete = nullptr;
    }
  } else {
    std::cout << "Index out of boundry" << std::endl << std::endl;
  }
}

template <typename T>
unsigned int LinkedList<T>::size() const {
  Node<T>* current = this->front();
  unsigned int size = 0;
  
  if (current != nullptr) {
    while (current != nullptr)
    {
      current = current->next;
      size++;
    }
  }

  return size;
}

template <typename T>
Node<T>* LinkedList<T>::front() const {
  return this->first;
}

template <typename T>
Node<T>* LinkedList<T>::back() const {
  Node<T>* current = this->front();
  
  if (current != nullptr) {
    while (current->next != nullptr)
    {
      current = current->next;
    }
  }

  return current;
}

template <typename T>
bool LinkedList<T>::empty() const {
  return (this->first == nullptr);
}

template <typename T>
void LinkedList<T>::removeDublicates() {
  T* foundData = new T[this->size()];
  unsigned int foundDataSize = 0;
  Node<T>* currentForGettingData = this->front();

  for (size_t i = 0; i < this->size(); i++) {
    bool flag = false;
    for (size_t j = 0; j < foundDataSize; j++) {
      if (foundData[j] == currentForGettingData->data) {
        flag = true;
        break;
      }
    }

    if (!flag) {
      foundData[foundDataSize++] = currentForGettingData->data;
    }
    
    currentForGettingData = currentForGettingData->next; 
  }

  unsigned int *indexes = new unsigned int[this->size()];
  unsigned int indexesSize = 0;

  for (size_t i = 0; i < foundDataSize; i++) {
    Node<T>* currentForDeletion = this->front();
    bool found = false;
    int index = 0;
    while (currentForDeletion != nullptr) {
      if (currentForDeletion->data == foundData[i]) {

        if (!found) {
          found = true;
        }else {
          indexes[indexesSize++] = index;
        }
      }
      currentForDeletion = currentForDeletion->next;
      index++;
    }
  }

  bool swaped = true;

  while (swaped)
  {
    swaped = false;
    for (size_t i = 0; i < indexesSize - 1; i++)
    {
      if (indexes[i] > indexes[i+1])
      {
        int temp = indexes[i+1];
        indexes[i+1] = indexes[i];
        indexes[i] = temp;
        swaped = true;
        break;
      }
    }
  }
  
  for (size_t i = 0; i < indexesSize; i++)
  {
    this->deleteAt(indexes[i]-i);
  }
  
}


template <typename T>
void LinkedList<T>::save() const {
  std::ofstream out("linkedLists.txt", std::ios::app);

  Node<T>* current = this->front();

  out << this->size() << " ";
  if (current != nullptr) {
    while (current != nullptr)
    {
      out << current->data << " ";
      current = current->next;
    }
  }
  out << '\n';

  out.close();
}

template <typename T>
void loadLists(Vector< LinkedList<T> >& vector) {
  std::ifstream in("linkedLists.txt");

  while (!in.eof())
  {
    LinkedList<T> current;
    int size = 0;
    in >> size;
    for (size_t i = 0; i < size; i++)
    {
      T data;
      in >> data;
      current.push_back(data);
    }
    vector.push_back(current);
  }
}