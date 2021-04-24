#pragma once

template <typename T>
struct Node {
  T data;
  Node<T>* next;

  Node<T>(T _data, Node<T>* _next) : data(_data), next(_next) {}
  Node<T>(Node<T>& other) : data(other->_data), next(other->_next) {}

};