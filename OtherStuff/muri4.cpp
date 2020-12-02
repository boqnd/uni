#include <iostream>
#include <cmath>

using namespace std;

int main(){
  long long n;

  cout << "n = ";
  cin >> n;

  while(!(n>=10000000))
  {
    cout << "n should be atleast 8 digit number. Try again..." << endl;
    cout << "n = ";
    cin >> n;
  }

  int digits = 0;
  long nCopy = n;

  while (nCopy > 0)
  {
    digits++;
    nCopy/=10;
  }
  
  for (int i = digits-1; i >= 0; i--)
  {
    int curr = (long long)(n/pow(10,i))%10;
    
    if (i>=digits/2)
    {
      curr++;
    }else{
      if (curr%2!= 0)
      {
        curr++;
      }
    }

    cout << curr;
  }  

  cout << endl;

  return 0;
}