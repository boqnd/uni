#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

template <typename T>
struct box {T data; box *next;};

/*Поставете тук реализация на функцията reverseList*/
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

TEST_CASE("Reverse basic")
{
    box<int> *l1 = new box<int>{1,
                         new box<int>{2,
                             new box<int>{3,
                                 new box<int>{4,
                                      new box<int>{5,
                                          new box<int>{6,
                                              new box<int>{7,
                                                  new box<int>{8,nullptr}}}}}}}};
    reverseList(l1,4);
    int expected[] = {4,3,2,1,5,6,7,8};
    for (int x: expected)
    {
        CHECK(x==l1->data);
        l1=l1->next;
    }

}

TEST_CASE("Reverse edges")
{
    box<int> *l1 = new box<int>{1, new box<int>{2,nullptr}};
    reverseList(l1,10);
    CHECK(l1->data == 2);
    CHECK(l1->next->data == 1);

    CHECK_NOTHROW(reverseList(l1->next,10));
    CHECK_NOTHROW(reverseList<int>(nullptr,10));
}

int main()
{

    doctest::Context().run();

    return 0;
}

