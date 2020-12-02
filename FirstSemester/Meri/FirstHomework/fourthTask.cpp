#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int roses, tulips, chrysants;
  char season, holiday;

  cin >> chrysants >> roses >> tulips >> season >> holiday;

  const double CHRYSANTS_PRICES[2] = {2.00, 3.75}, ROSES_PRICES[2] = {4.10, 4.50}, TULIPS_PRICES[2] = {2.50, 4.15};

  const int HOT_SEASONS = 0;
  const int COLD_SEASONS = 1;
  
  double rosesPrice, tulipsPrice, chrysantsPrice;

  switch(season)
  {
    case 'P': case 'L':
      rosesPrice = ROSES_PRICES[HOT_SEASONS];
      tulipsPrice = TULIPS_PRICES[HOT_SEASONS];
      chrysantsPrice = CHRYSANTS_PRICES[HOT_SEASONS];
      break;
    case 'E': case 'Z':
      rosesPrice = ROSES_PRICES[COLD_SEASONS];
      tulipsPrice = TULIPS_PRICES[COLD_SEASONS];
      chrysantsPrice = CHRYSANTS_PRICES[COLD_SEASONS];
      break;
  }

  if(holiday == 'Y')
  {
    rosesPrice += rosesPrice * 0.15;
    tulipsPrice += tulipsPrice * 0.15;
    chrysantsPrice += chrysantsPrice * 0.15;
  }
  
  double sum = roses*rosesPrice + tulips*tulipsPrice + chrysants*chrysantsPrice;


  if (tulips > 7 && season == 'P')
  {
    sum -= sum * 0.05;
  }

  if (roses >= 10 && season == 'Z')
  {
    sum -= sum * 0.10;
  }

  if (roses + tulips + chrysants > 20)
  {
    sum -= sum * 0.20;
  }

  sum += 2;
  
  cout << std::fixed << std::setprecision(2) << sum << endl;

  return 0;
}