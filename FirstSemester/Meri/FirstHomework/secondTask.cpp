#include <iostream>

using namespace std;

int main() {
  double age, phonePrice, toyPrice;

  cout << "age: ";
  cin >> age;
  cout << "phone price: ";
  cin >> phonePrice;
  cout << "toy price: ";
  cin >> toyPrice;

  int moneySaved;

  for (int i = 1; i <= age; i++)
  {
    if (i%2 == 0)
    {
      moneySaved += 10 * (i/2) - 1;
    }else{
      moneySaved += toyPrice;
    }
  }

  if (moneySaved < phonePrice)
  {
    cout << "NO!" << endl;
    cout << phonePrice - moneySaved << endl;
  }else {
    cout << "YES!" << endl;
    cout.precision(2);
    cout << (moneySaved - phonePrice) << endl;
  }
  
  return 0;
}