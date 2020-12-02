#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int a, b, n, sum = 0;

  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "n = ";
  cin >> n;

  for (int an = 1, bn = n; an <= n; an++, bn--)
  {
    sum += pow(a,an)*pow(b,bn);
  }

  cout << "sum = " << sum << endl;

  return 0;
}