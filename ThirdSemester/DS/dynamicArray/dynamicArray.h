#include <cstddef>

template <typename T>
class DynamicArray {
  private:
    int size;
    int capacity;
    T* data;

  public:
    DynamicArray();
    DynamicArray(const size_t& size);
    DynamicArray(const DynamicArray<T>& other);
    ~DynamicArray();

    DynamicArray<T>& operator= (const DynamicArray<T> other);
    void pushBack(const T& value);
    void popBack();
    void resize(const size_t& newSize);
    void reserve(const size_t& newCapacity);
};

template<typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), size(0), capacity(0) {}

template<typename T>
DynamicArray<T>::DynamicArray(const size_t& size) {
  this->size = size;
  this->capacity = size;
  this->data = new T()[this->size];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new T()[this->capacity];
  for (size_t i = 0; i < this->size; i++)
  {
    this->data[i] = other.data[i];
  }
}