#include <iostream>

using namespace std;

//TASK 1
int fact(int n){
  if (n == 1) {
    return 1;
  }

  return n*fact(n-1);
}

int factSum(int n) {
  if (n == 1) {
    return 1;
  }

  return fact(n) + factSum(n-1);
}

//TASK 2

bool isUpper(char a){
  if (a >= 'A' && a <= 'Z') {
    return true;
  }
  return false;
}

bool isLower(char a){
  if (a >= 'a' && a <= 'z') {
    return true;
  }
  return false;
}

bool isDigit(char a){
  if (a >= '0' && a <= '9') {
    return true;
  }
  return false;
}

void helperTwo(const char str[], int digits, int upper, int lower){
  if (*str == '\0') {
    cout << "Digits: " << digits << endl;
    cout << "Capital: " << upper << endl;
    cout << "Small: " << lower << endl;
  }else {
    if (isUpper(*str)) {
      upper++;
    }else if (isLower(*str)) {
      lower++;
    }else if (isDigit(*str)) {
      digits++;
    }

    helperTwo(str+1, digits, upper, lower);
  }
}

void taskTwo(const char str[]){
  helperTwo(str, 0, 0, 0);
}

//TASK 3
int TwoOnPowerOf(int pow){
  int result = 1;

  while (pow != 0) {
    result *= 2;
    pow--;
  }

  return result;
}


int helperThree(int num, int index){
  if (num == 0) {
    return 0;
  }

  if (num % 2 == 1) {
    return TwoOnPowerOf(index);
  }

  return helperThree(num/2, ++index);
}

int taskThree(int num) {
  return helperThree(num, 0);
}



int main(){

  //cout << factSum(3) << endl;
  //cout << factSum(5) << endl;

  //taskTwo("8AFGcda567");

  // cout << taskThree(26) << endl;
  // cout << taskThree(35) << endl;

  return 0;
}
