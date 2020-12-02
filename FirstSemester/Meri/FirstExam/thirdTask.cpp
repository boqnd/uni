#include <iostream>
#include <math.h>

using namespace std;

int main(){
  int n;

  cout << "n = ";
  cin >> n;

  int numbers[n];

  //Вход
  for (int i = 0; i < n; i++)
  {
    cout << "number[" << i+1 << "] = ";
    cin >> numbers[i];
  }

  //В този цикъл въртим от втория елемент до последния,
  // защото проверяваме всеки елемент дали се съдържа в предишния.
  bool flag = 0;
  for (int i = 1; i < n; i++)
  {
    //cout << numbers[i] << endl;

    int a = numbers[i-1];
    int b = numbers[i];
    int bCopy = b;
    //123435
    //23

    //тук намирам на колко трябва да разделя модулно първото, 
    // за да получа евентуално второто. Пример: а = 1234, б = 234 -> 1234 % 1000 = 234 (съдържа се).
    int divider = 1;

    while(bCopy != 0)
    {
      divider *= 10;
      bCopy /= 10;
    }

    while(a != 0)
    {
      //cout<<a<<endl;
      if(a % divider == b)
      {
        flag = 1;
        break;
      }else{a /= 10;}
    }

    if(flag)
    {
      break;
    }
  }

  if(flag)
  {
    cout << "Yes" << endl;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += numbers[i];
    }
    double average = sum/n;
    cout << average << endl;
  }
  
  
  return 0;
}