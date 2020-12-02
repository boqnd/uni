/*
  Дадени са две числа d (ден), m (месец) и y (година),
   които формират дата. Да се напише програма,
    която отпечатва датата, която ще бъде след 5 дни.
     Например 5 дни след 28.03.2019 е датата 2.04.2019.
      Приемаме, че месеците:
       април, юни, септември и ноември имат по 30 дни,
        февруари има 28 или 29 дни (във високосна година),
         а останалите имат по 31 дни. Месеците да се отпечатат с водеща нула,
          когато са едноцифрени (например 01, 08).
*/

#include <iostream>

using namespace std;

bool isLeap (int year){
  //If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
  //If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
  //If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
  //The year is a leap year (it has 366 days).
  //The year is not a leap year (it has 365 days).
  if (year % 4 == 0)
  {
    if (year % 100 == 0)
    {
      if (year % 400 == 0)
      {
        return 1;
      }
    }else{
      return 1;
    }
  }

  return 0;
}

int monthDays (int month, bool leap){
  int days;
  switch(month)
  {
    case 4: case 6: case 9: case 11:
      days = 30;
      break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      days = 31;
      break;
    case 2:
      if(leap)
      {
        days = 29;
        break;
      }
      days = 28;
      break;
    default:
      days = 0;
      break;
  }

  return days;
}

void printDate(int day, int month, int year)
{
  cout << day << ".";;
  if (month < 10)
  {
    cout << 0 << month;
  }else{
    cout << month;
  }
  cout << "." << year << endl;
}

int main() {

  int d, m, y;

  cout << "day: ";
  cin >> d;
  cout << "month: ";
  cin >> m;
  cout << "year: ";
  cin >> y;

  int daysInMonth = monthDays(m, isLeap(y));

  d += 5;

  if (d > daysInMonth)
  {
    m++;

    if (m > 12)
    {
      m = 1;
      y++;
    }
    
    d -= daysInMonth;
  }

  printDate(d,m,y);

  return 0;
}