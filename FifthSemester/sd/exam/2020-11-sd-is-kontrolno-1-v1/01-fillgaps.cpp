#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

template <typename T>
struct box {T data; box *next;};

/*Поставете тук реализация на функцията fillGaps*/
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

TEST_CASE("fillGaps basic")
{
    box<int> *l1 = new box<int>{1,
                         new box<int>{3,
                             new box<int>{5,nullptr}}};

    fillGaps(l1);
    for (int i = 1; i <= 5; ++i)
    {
        CHECK(l1->data == i);
        l1 = l1->next;
    }
}

TEST_CASE("fillGaps edges")
{

    box<int> *l2 = new box<int>{1,nullptr};
    fillGaps(l2);
    CHECK(l2->next == nullptr);

    CHECK_NOTHROW(fillGaps<int>(nullptr));
}

int main()
{

    doctest::Context().run();

    return 0;
}

