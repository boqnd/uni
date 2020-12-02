#include<iostream>
#include<cmath>

using namespace std;

//Задача 1
//Напишете програма, която приема число n (2 <= n <= 9) и число в n-тична бройна система, 
//  и превръща числото в десетична бройна система. 
//    Пример: Вход: 7 63 Изход: 45 (Обяснение: 3(7^0) + 6(7^1) = 3 + 42 = 45)
//Забележка: Приемете, че данните които ще се въвеждат за числото ще са коректни.

int main(){
  int n, number;

  cin >> n >> number;

  int result = 0;

  for (int i = 0; number > 0; i++, number/=10)
  {
    int power = 1;
    for (int p = 0; p < i; p++)
    {
      power *= n;
    }
    
    result += number%10 * power;
  }
  
  cout << result << endl;

  return 0;
}