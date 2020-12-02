#include <iostream>

using namespace std;

int main(){
  const int THREE = 3;
  const int FOUR = 4;
  const int SIX = 6;

  int wheelsAvailable;

  cout << "Wheels: ";
  cin >> wheelsAvailable;

  int l = wheelsAvailable/THREE;
  int count = 0;
  for (int i = 0; i <= l; i++)
  {
    for (int k = 0; k <= l; k++)
    {
      for(int p = 0; p <= l; p++)
      {
        if(i*THREE + k*FOUR + p*SIX == wheelsAvailable)
        {count++;}
      }
    }
  }
  
  cout << count;

  return 0;
}