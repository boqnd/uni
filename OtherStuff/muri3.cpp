#include <iostream>
#include <cmath>

using namespace std;

int main(){
  double a, b, n, sum = 0;

  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "n = ";
  cin >> n;

  for (int p = 0; p <= n; p++)
  {
    sum += pow((a/b),2*p+1);
  }

  cout << "sum = " << sum << endl;

  return 0;
}