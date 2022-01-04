#include <iostream>

// void printMaxTwo(int* arr, int size){
//   bool switched = true;
//   while (switched)
//   {
//     switched = false;
//     for (size_t i = 0; i < size - 1; i++)
//     {
//       if (arr[i] < arr[i+1])
//       {
//         int temp = arr[i];
//         arr[i] = arr[i+1];
//         arr[i+1] = temp;
//         switched = true;
//         break;
//       }
//     }
//   }

//   int n = (size < 2 ? size : 2); 
  
//   for (size_t i = 0; i < n; i++)
//   {
//     std::cout << arr[i] << " ";
//   }
  
// }

bool AllUnique(std::string str) {
  for (size_t i = 0; i < str.size(); i++)
  {
    for (size_t j = i+1; j < str.size(); j++)
    {
      if (str[i] == str[j])
      {
        return false;
      }
    }
  }
  return true;
}

int f(int a, int b) {
  if(a==1) {
    return b;
  }
  return f(a/2,b*2) + (a%2==1?b:0);
}

int foo(int num) {
  if (num < 10) {
    return num;
  }

  return foo(num/10 + num%10);
}


int main (int argc, char** argv) {
  std::cout << f(5,10);
  return 0;
}