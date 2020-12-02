#include <iostream>

using namespace std;

int main(){
  bool dryCough, soreThroat, lackOfSenseOfSmell, positivePCR;
  double temperature;
  const double minTemp = 37.5;
  const double maxTemp = 40.5;

  cout << "Dry Cough (1/0): ";
  cin >> dryCough;
  cout << "Sore Throat (1/0): ";
  cin >> soreThroat;
  cout << "Lack Of Sense Of Smell (1/0): ";
  cin >> lackOfSenseOfSmell;
  cout << "Positive PCR (1/0): ";
  cin >> positivePCR;
  cout << "Temperature: ";
  cin >> temperature;
  
  bool sick = (positivePCR || (dryCough && lackOfSenseOfSmell) || (dryCough && soreThroat && (temperature >= minTemp && temperature <= maxTemp)));

  cout << "--> SICK: " << sick << endl;

  return 0;
}
