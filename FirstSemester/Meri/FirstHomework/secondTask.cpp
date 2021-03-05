#include <iostream>
#include <iomanip>

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
    cout << fixed << setprecision(2) << phonePrice - moneySaved << endl;
  }else {
    cout << "YES!" << endl;
    cout << std::fixed << std::setprecision(2) << (moneySaved - phonePrice) << endl;
  }
  
  return 0;
}