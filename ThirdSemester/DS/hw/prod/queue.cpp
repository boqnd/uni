#include <vector>

template <typename T>
class queue {
  private:
    std::vector<T> data;
  
  public:
    bool empty() {
      return data.empty();
    }

    T& front() {
      return data.front();
    }

    T back() {
      return data.back();
    }

    void push(T element) {
      data.push_back(element);
    }

    void pop() {
      data.erase(data.begin());
    }

    size_t size() {
      return data.size();
    }
};