#include <iostream>
#include <array>

using namespace std;

//Car wheels

std::array<int,3> numberOfWheelsOptions = {3,4,6};
int counter = 0;
bool flag = false;

int findSum(int n)
{
  int sum = 0;

  while (n > 0)
  {
    sum += n%10;
    n/=10;
  }

  return sum;
}

//NOT WORKING
// int findCombosBeta (int n, int curr, int limit){
//   if (false)
//   {
//     return 0;
//   }

//   int sum = findSum(curr);
//   // cout << "1 " << n << endl;
//    cout << curr << endl;

//   if ( sum < limit)
//   {
//     findCombos(n, curr * 10 + numberOfWheelsOptions[n], limit);
    
//     if ((numberOfWheelsOptions[n] != numberOfWheelsOptions.back()) && flag == 0)
//     {
//       findCombos(n+1, curr * 10 + numberOfWheelsOptions[n+1], limit);
//     }
//   }else if(sum == limit){
//     counter++;
//   }
//   return 0;
// }

int findCombos (int n, int curr, int limit){
  int sum = findSum(curr);

  if(sum == limit){
    counter++;
    cout<<curr<<endl;
  }
  if(sum<limit){
    for (int i = n; i < 3; i++)
    { 
      findCombos(i, curr * 10 + numberOfWheelsOptions[i], limit);
    }
  }
  return 0;
}

//n = 3
//3 < 12
//33 < 12
//333 < 12
//3333 = 12
//3334 > 12
//334 < 12
//3344 > 12
//3346 > 12
//34 < 12
//344 < 12
//3444 > 12
//34


int main(){
  // int count = sizeof(numberOfWheelsOptions)/sizeof(*numberOfWheelsOptions);
  // for(int i = 0; i < count; i++){
  //   cout << numberOfWheelsOptions[i] << endl;
  // }

  findCombos(0,0,27);
  cout << "Number of combinaitons: " << counter << endl;
  //cout << numberOfWheelsOptions[0];
}