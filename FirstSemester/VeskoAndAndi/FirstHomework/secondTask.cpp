#include <iostream>
//Interesting number
int main(){
  int number;
  std::cout << "Give me a number and I will tell you whether it is interesting or not." << std::endl << " --> number = ";
  std::cin >> number;

  int n = number;
  int sum = 0;

  while (n > 0)
  {
    sum += n%10;
    n/=10;
  }

  if(number % sum == 0)
  {
      std::cout << "Yes, the number " << number << " is interesting!" << std::endl;
  }else{
      std::cout << "No, the number " << number << " is not interesting!" << std::endl;
  }

  return 0;
}