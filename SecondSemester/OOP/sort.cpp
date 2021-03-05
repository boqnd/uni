#include <iostream>

using namespace std;

template <typename T>
void sort(T* arr, unsigned int size) {
  bool flag = true;
  while(flag) {
    flag = false;
    for (int i = 0; i < size - 1; i++) {
      if (arr[i] > arr[i+1]) {
        T temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        flag = true;
      }
    }
  }
}

struct Student {
  int fn;
  char* name;
  bool operator> (Student& other) {
    return fn > other.fn;
  }
};



int main() {
  int arr[4] = {3,5,1,2};
  sort(arr,4);
  cout << arr[0] << arr[1] << arr[2] << arr[3] << endl; 

  Student stds[3] = {{4532, "Ivan"}, {1234, "Stoyan"}, {3542, "Boyan"}};
  sort(stds,3);
  cout << stds[0].name << stds[1].name << stds[2].name << endl;
  return 0;
}