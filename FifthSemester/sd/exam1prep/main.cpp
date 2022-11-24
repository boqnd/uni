#include <iostream>
#include <cmath>
#include <stack>
#include <exception>
#include <cstring>

struct Node {
    int data;
    Node* next;
};

void sort_by_absolute_value(Node* first) {
    if(first == nullptr){
        return;
    }
    Node* curr = first;
    Node* next = curr->next;
    bool flag = false;

    while (!flag) {
        flag = true;
        curr = first;
        next = curr->next;
        while (next != nullptr) {
            if(abs(curr->data) > abs(next->data)) {
                int helper = next->data;
                next->data = curr->data;
                curr->data = helper;
                flag = false;
            }
            next = next->next;
            curr = curr->next;
        }
    }
}

Node* sort_sorted_by_abs(Node* first) {
    sort_by_absolute_value(first);
    Node* curr = first;
    Node* next = curr->next;
    Node* helper = curr;
    while (next != nullptr){
        if(next->data < 0) {
            curr->next = next->next;
            next->next = helper;
            helper = next;
            next = curr->next;
        } else {
            curr = curr->next;
            next = next->next;
        }

    }
    return helper;
}

bool is_palindrome_stack(Node* head){
    Node* current = head;
    std::stack<int> s;
    while (current != nullptr){
        s.push(current->data);
        current = current->next;
    }
    current = head;
    while (current != nullptr) {
        if(s.top() == current->data){
            s.pop();
            current = current->next;
        } else {
            return false;
        }
    }
    return true;
}

// Node* recursion_reverse(Node* current, Node* reversed){
//     if(current == nullptr){
//         return reversed;
//     }
//     Node* next = new Node{current->data, reversed};
//     recursion_reverse(current->next, next);
// }

// void recursion_reverse_two(Node* current, Node* first, bool flag, int count){
//     if(current == nullptr){
//         return;
//     }
//     if (flag) {
//         recursion_reverse_two(current->next, first, true, ++count);
//         for (size_t i = 0; i < count; i++) {
//             first = first->next;
//         }
//         recursion_reverse_two(first, current, false, 0);
//     } else {
//         std::cout << "test: " << current->data << ":" << first->data << std::endl;
//     }
//         // std::cout << "test: " << current->data << ":" << first->data << std::endl;
//     // std::cout << current->data << " ";
// }

// bool is_palindrome_no_stack(Node* head){
//     Node* reverse_head = recursion_reverse(head,nullptr);
//     while (head != nullptr) {
//         if(head->data != reverse_head->data){
//             return false;
//         }
//         head = head->next;
//         reverse_head = reverse_head->next;
//     }
//     return true;
// }

// template<class T>
// bool is_palindrome_no_stack_two(Node* head){
//     return recursion_reverse_two(head, head);
// }

bool has_cycle(Node* head) {
    Node* turtle = head;
    Node* rabbit = head->next;
    while (turtle->next != nullptr && rabbit->next->next !=nullptr) {
        if(turtle == rabbit){
            return true;
        }
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    return false;
}


//TASK4===========================================================
//Намерете елемент n в едносвързан списък, използвайки двоично търсене.
int size(Node* head) {
  int count = 0;

  while (head != nullptr) {
    count++;
    head = head->next;
  }

  return count;
}

Node* binary_search(Node* head, int n) {
  int index = size(head)/2;
  Node* curr = head;
  for (size_t i = 0; i < index; i++)
  {
    curr = curr->next;
  }

  while (curr != nullptr) {
    std::cout << index << std::endl;

    if (curr->data == n) {
      break;
    } else if (curr->data > n) {
      index = index/2;
    } else if (curr->data < n) {
      index += (size(head)-index)/2+1;
    }


    if (index >= size(head) || index < 0) {
      curr = nullptr;
      break;
    }

    curr = head;
    for (size_t i = 0; i < index; i++)
    {
      curr = curr->next;
    }
  }

  return curr;
}


// TASK 5 (template)
// Групирайте всички елементи, които са на нечетна позиция, последвани от тези на четна позиция, на подаден едносвързан списък.
//  Пример: Вход: 1 -> 2 -> 3 -> 4 -> 5 Изход: 1 -> 3 -> 5 -> 2 -> 4

Node* group(Node* head) {
  std::cout << "kur" << std::endl;

  Node* res = new Node{head->data, nullptr};
  Node* resCurr = res;

  Node* curr = head;

  for (size_t i = 0; curr; i++)
  {
    if (i%2 == 0 && i != 0)
    {
      resCurr->next = new Node{curr->data, nullptr};
      resCurr = resCurr->next;
    }
    curr = curr->next;
  }

  curr = head;
  for (size_t i = 0; curr; i++)
  {
    if (i%2 != 0)
    {
      resCurr->next = new Node{curr->data, nullptr};
      resCurr = resCurr->next;
    }
    curr = curr->next;
  }

  return res;
}


// Пояснение: Първата група е от елементите на нечетна позиция (1 3 и 5) в списъка,
//  последвани от тези на четна позиция (2 и 4).


// TASK 6
// Имаме следната редица: 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 ... По подадено число k създайте списък с първите k елемента от 
// редицата по-горе.Пример: Вход: k = 5 Изход: 1 -> 2 -> 2 -> 3 -> 3

// TASK 7
// Имате списък, който е съставен от две сортирани във възходящ ред части. 
// Напишете функция, която намира двете части и ги свързва в нов сортиран списък. 
// Пример: Вход: 1 -> 6 -> 7 -> 10 -> 2 -> 4 -> 8 Изход: 1 -> 2 -> 4 -> 6 -> 7 -> 8 -> 10

void print(Node* head) {
    while (head != nullptr){
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main() {

    Node* kur = new Node{1,
                        new Node{2,
                        new Node{3,
                        new Node{4,
                        new Node{5,
                        new Node{6,nullptr}}}}}};

    print(group(kur));
    return 0;
}