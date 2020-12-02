#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n;

  cout << "n = ";
  cin >> n;

  while(!(n>=10000 && n<=99999))
  {
    cout << "n should be a 5 digit number. Try again..." << endl;
    cout << "n = ";
    cin >> n;
  }

  for (int i = 10000, counter = 1; counter <= 5; i/=10, counter++)
  {
    int devider;
    if(counter % 2 == 0){devider = 3;}
    else{devider = 2;}
    
    cout << ((n/i)%10)%devider;
  }  

  cout << endl;

  return 0;
}