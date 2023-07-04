#define DOCTEST_CONFIG_IMPLEMENT
#include "./doctest.h"
#include "./treeutils.cpp"

#include <vector>

/*
======================
Решение на задачата:
======================
*/
template <typename T>
void diffHelper(box<T>* t1, box<T>*t2, std::vector<T>& res) {
    if (!t2 && t1) {
        res.push_back(t1->data);
        diffHelper<T>(t1->left, nullptr, res);
        diffHelper<T>(t1->right, nullptr, res);
    } else if(t2 && t1) {
        diffHelper<T>(t1->left, t2->left, res);
        diffHelper<T>(t1->right, t2->right, res);
    }
}

template <typename T>
std::vector<T> diff(box<T>* t1, box<T>*t2) {
    std::vector<T> res;

    diffHelper<T>(t1,t2,res);

    return res;
}


/*
======================
Тестове
======================
*/
TEST_CASE("Test Edges")
{
     box<int> *t1=nullptr,
              *t2=nullptr;

    setAt(t2,"",0);
    setAt(t2,"R",0);

    CHECK(diff(t1,t2).size()==0);
    CHECK(set_equals(diff(t2,t1),{0}));
}

TEST_CASE("Test Diff") 
{
    box<int> *t1=nullptr,
             *t2=nullptr;

    setAt(t1,"",10);
    setAt(t1,"L",20);
    setAt(t1,"R",30);
    setAt(t1,"RL",40);
    setAt(t1,"RR",50);
    setAt(t1,"RRL",60);

    setAt(t2,"",0);
    setAt(t2,"R",0);

    CHECK(set_equals(diff(t1,t2),{20,40,50,60}));

}

int main()
{
    doctest::Context().run();
}