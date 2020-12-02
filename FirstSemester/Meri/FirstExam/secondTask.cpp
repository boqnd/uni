#include <iostream>

using namespace std;

int main(){
  int n;

  cout << "n = ";
  cin >> n;

  int counter = 0;

  while(n != 1)
  {
    //cout << n << endl;
    counter ++;
    if(n % 2 == 0){
      n /= 2;
      continue;
    }
    n *= 3;
    n++;
  }

  //cout << n << endl;
  cout << "count: " << ++counter << endl;

  return 0;
}