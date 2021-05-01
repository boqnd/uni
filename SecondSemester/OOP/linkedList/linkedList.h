#pragma once
#include "node.cpp"

template <typename T>
class LinkedList {

  private:
    Node<T>* first;

  public:
    LinkedList();
    LinkedList(const LinkedList<T>& other);
    ~LinkedList();
    LinkedList<T>& operator = (const LinkedList<T>& other);

    void print() const; // - отпечатва елементите на списъка разделени с '->'
    void push(const T& data);// - добавя елемент в началото на списъка
    void push_back(const T& data);// - добавя елемент в края на списъка
    void pop();// - премахва елемент в началото на списъка
    void pop_back();// - премахва елемент в края на списъка
    void clear();// - премахва всички елементи
    void insertAfter(const T& data, const unsigned int& index);// - добавя елемент след определена позиция в списъка
    void deleteAt(const unsigned int& index);// - премахва елемент след определена позиция в списъка
    unsigned int size() const;//  - размер
    Node<T>* front() const;// - първи елемент
    Node<T>* back() const;// - последен елемент
    bool empty() const;// - проверява дали списъка е празен

    void removeDublicates();// - премахва всички еднакви елементи в списъка

    void save() const;
};