#include <iostream>

template <typename T>
struct Node {
  T data;
  Node<T>* next;

  Node() {
    next = nullptr;
  }

  Node(T value) {
    data = value;
    next = nullptr;
  }
};

template <typename T>
struct LinkedList {
  Node<T>* first;

  LinkedList () {
    first = nullptr;
  }

  void push(T value) {
    if(first == nullptr) {
      first = new Node<T>(value);
    } else {
      Node<T>* curr = first;
      while (curr->next != nullptr) {
        Node<T>* next = curr->next;
        curr = next;
      }
      curr->next = new Node<T>(value);
    }
  }

  void print() {
    if(first == nullptr) {
      std::cout << "[ ]" << std::endl;
    }else {
      std::cout << "[ ";
      Node<T>* curr = first;
      while (curr->next != nullptr) {
        std::cout << curr->data << " ";
        Node<T>* next = curr->next;
        curr = next;
      }
      std::cout << curr->data << " ]" << std::endl;
    }
  }

  void swap(int i, int j) {
    Node<T>* curr = first;
    int ctr = 0;
    T d1;
    T d2;
    while (curr->next != nullptr) {
      if (ctr == ((i < j) ? i : j))
      {
        d1 = curr->data;
      }
      if (ctr == ((i > j) ? i : j))
      {
        d2 = curr->data;
      }  
      ctr++;
      Node<T>* next = curr->next;
      curr = next;
    }

    ctr = 0;
    curr = first;
    while (curr->next != nullptr) {
      if (ctr == ((i < j) ? i : j))
      {
        curr->data = d2;
      }
      if (ctr == ((i > j) ? i : j))
      {
        curr->data = d1;
      }  
      ctr++;
      Node<T>* next = curr->next;
      curr = next;
    }
  }

  int getSize() {
    Node<T>* curr = first;
    int ctr = 0;
    T d1;
    T d2;
    while (curr->next != nullptr) {
      ctr++;
      Node<T>* next = curr->next;
      curr = next;
    }

    return ctr+1;
  }

  T operator[] (int i) {
    T result;
    Node<T>* curr = first;
    int ctr = 0;
    while (curr != nullptr) {

      if (ctr == i)
      {
        result = curr->data;
        break;
      }
      ctr++;
      Node<T>* next = curr->next;
      curr = next;
    }

    return result;
  }
};

template <typename T>
bool isPalindrome(LinkedList<T>& list) {
  for (size_t i = 0; i < (list.getSize()/2); i++)
  {
    if (list[i] != list[list.getSize()-1-i])
    {
      return false;
    }
  }
  return true;
}

int main() {
  LinkedList<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(2);
  a.push(1);

  a.swap(1,3);
  a.print();
  std::cout << std::boolalpha << isPalindrome(a) << std::endl;

  a.swap(1,2);
  a.print();
  std::cout << std::boolalpha << isPalindrome(a) << std::endl;

  return 0;
}