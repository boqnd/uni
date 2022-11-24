#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

template <typename T>
struct box {T data; box *next;};

/*Поставете тук реализация на функцията makeFib*/
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

TEST_CASE("makeFib basic")
{
    box<int> *l1 = new box<int>{1,
                         new box<int>{1,
                             new box<int>{2,
                                 new box<int>{2,
                                      new box<int>{2,
                                          new box<int>{3,
                                              new box<int>{5,
                                                  new box<int>{9,nullptr}}}}}}}};
    makeFib(l1);
    int expected[] = {1,1,2,3,5};
    for (int x: expected)
    {
        CHECK(x==l1->data);
        l1=l1->next;
    }

}

TEST_CASE("makeFib edges")
{
    box<int> *l2 = new box<int>{1,nullptr};
    CHECK_NOTHROW(makeFib(l2));
    CHECK(l2->data == 1);

    box<int> *l3 = new box<int>{1,new box<int>{2,nullptr}};
    CHECK_NOTHROW(makeFib(l3));
    CHECK(l3->next->data == 2);

    CHECK_NOTHROW(makeFib<int>(nullptr));
}

int main()
{

    doctest::Context().run();

    return 0;
}

