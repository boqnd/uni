#define DOCTEST_CONFIG_IMPLEMENT
#include "./doctest.h"
#include "./treeutils.cpp"

#include <vector>
#include <queue>

/*
======================
Решение на задачата:
======================
*/
template <typename T>
std::vector<T> levelsReverse(box<T>* t) {
    std::vector<T> res;

    std::queue<box<T>*> q;
    if (t) q.push(t);

    while (!q.empty()) {
        box<T>* curr = q.front();

        res.push_back(curr->data);

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
        q.pop();
    }

    std::vector<T> res_rev;
    for (int i = res.size()-1; i >= 0; i--)
    {
        res_rev.push_back(res[i]);
    }

    return res_rev;
}

/*
======================
Тестове
======================
*/
TEST_CASE("Edges") 
{
    box<int> *t=nullptr;

    CHECK(levelsReverse(t).size()==0);

    setAt(t,"",10);

    std::vector<int> expected = {10};
    CHECK(expected==levelsReverse(t));

}


TEST_CASE("Test Levels Reverse") 
{
    box<int> *t=nullptr;

    setAt(t,"",10);
    setAt(t,"L",20);
    setAt(t,"R",30);
    setAt(t,"RL",40);
    setAt(t,"RR",50);
    setAt(t,"RRL",60);

    std::vector<int> expected = {60, 50, 40, 30, 20, 10};
    CHECK(expected==levelsReverse(t));
}

int main()
{
    doctest::Context().run();
}