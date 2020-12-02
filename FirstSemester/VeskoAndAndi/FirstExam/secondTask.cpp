#include<iostream>

using namespace std;

/*
Две изречения са анаграми едно на друго ако съдържат еднакъв брой букви
 и всяка буква от едното изречение се среща еднакъв брой пъти и в двете изречения.
  Не правим разлика между главни и малки букви.
   Работим само с букви от латинската азбука.
    Примери: "Astronomer" и "Moon starer" са анаграми, "ABBA" и "baba" са анаграми.
     "Mississippi" и "Sipi mi sipi" не са анаграми.
      Напишете програма, която приема две изречения, съдържащи латински букви и евентуално интервали,
       и проверява дали двете изречения са анграми едно на друго.
*/
const int MAX_SIZE = 100;

int main(){

  char strOne[MAX_SIZE], strTwo[MAX_SIZE];

  cout << "first string: ";
  cin.getline(strOne, MAX_SIZE);

  cout << "second string: ";
  cin.getline(strTwo, MAX_SIZE);

  for (int i = 0; i < strOne[i] != '\0'; i++)
  {
    if (strOne[i] >= 'A' && strOne[i] <= 'Z')
    {
      strOne[i] += ('a' - 'A');
    }
  }
  for (int i = 0; i < strTwo[i] != '\0'; i++)
  {
    if (strTwo[i] >= 'A' && strTwo[i] <= 'Z')
    {
      strTwo[i] += ('a' - 'A');
    }
  }

  bool anagram = true;

  for (int i = 0; strOne[i] != '\0'; i++)
  {
    if (strOne[i] >= 'a' && strOne[i] <= 'z')
    {
      int couterOne = 0, counterTwo = 0;

      for (int o = 0; strOne[o] != '\0'; o++)
      {
        if (strOne[o] == strOne[i])
        {
          couterOne++;
        }
      }
      
      for (int s = 0; strTwo[s] != '\0'; s++)
      {
        if (strTwo[s] == strOne[i])
        {
          counterTwo++;
        }
      }
      
      if (couterOne != counterTwo)
      {
        anagram = false;
        break;
      }
    }
  }
  
  for (int i = 0; strTwo[i] != '\0'; i++)
  {
    if (strTwo[i] >= 'a' && strTwo[i] <= 'z')
    {
      int couterOne = 0, counterTwo = 0;

      for (int o = 0; strOne[o] != '\0'; o++)
      {
        if (strOne[o] == strTwo[i])
        {
          couterOne++;
        }
      }
      
      for (int s = 0; strTwo[s] != '\0'; s++)
      {
        if (strTwo[s] == strTwo[i])
        {
          counterTwo++;
        }
      }
      
      if (couterOne != counterTwo)
      {
        anagram = false;
        break;
      }
    }
  }
  
  if (anagram)
  {
    cout << "Aнаграми са!" << endl;
  }else{
    cout << "Не са анаграми!" << endl;
  }

  return 0;
}