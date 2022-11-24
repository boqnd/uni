#include <iostream>
#include <stack>

template <typename T>
struct box {T data; box *next;};

template <typename T>
void fillGaps(box<T>* head) {
  if (head) {
    while (head->next) {
      if (head->data+1 < head->next->data) {
        box<T>* newBox = new box<T>{head->data+1, head->next};
        head->next = newBox;
      }
      head = head->next;
    }
  }
}

template <typename T>
void makeFib(box<T>* head) {
  if (head && head->next) {
    box<T>* first = head;
    box<T>* second = first->next;
    box<T>* next = second->next;

    while (next) {
      if (first->data + second->data != next->data) {
        box<T>* toDel = next;
        second->next = next->next;
        next = next->next;
        delete[] toDel;
      } else {
        first = first->next;
        second = second->next;
        next = next->next;
      }
    }
  }
}

// template <typename T>
// box<T>* reverseHelper(box<T>* head, unsigned int n, box<T>* next) {
//   if (n == 0)
//   {
//     return nullptr;
//   }

//   reverseHelper(head->next, n-1, head);
//   return new box<T>{head->data, next}
// }

// 1 2 3 4
template <typename T>
void reverseList(box<T>* head, unsigned int n) {
  if (head)
  {
    std::stack<T> s;
    box<T>* curr = head;

    for (size_t i = 0; i < n && curr; i++)
    {
      s.push(curr->data);
      curr = curr->next;
    }
    for (size_t i = 0; i < n && head; i++)
    {
      head->data = s.top();
      s.pop();

      head = head->next;
    }
  }
}

template<typename T>
void print(box<T>* head) {
  while (head) {
    std::cout << head->data << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {

    box<int> *l1 = new box<int>{1,
                         new box<int>{2,
                             new box<int>{3,
                                 new box<int>{4,
                                      new box<int>{5,
                                          new box<int>{6,
                                              new box<int>{7,
                                                  new box<int>{8,nullptr}}}}}}}};

  print(l1);
  reverseList(l1,4);
  print(l1);


  return 0;
}