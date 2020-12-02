//Na Traicho provala
#include <iostream>

using namespace std;
// По зададени оценки от трите домашни, 
// двете контролни на задачи, 
// двете контролни на теория и 
// оценки от изпитите на задачи и теория, 
// да се напишат булеви изрази дали Трайчо се е освободил от теория, 
// от задачи и дали е взел функционално програмиране.

int main(){
  double hwOne, hwTwo, hwThree;
  double practiceTestOne, practiceTestTwo;
  double theoryTestOne, theoryTestTwo;
  bool freeOfPractice = false, freeOfTheory = false;
  double practiceExam, theoryExam;

  cout << "Home work one: ";
  cin >> hwOne;
  cout << "Home work two: ";
  cin >> hwTwo;
  cout << "Home work three: ";
  cin >> hwThree;

  cout << "Practice Test One: ";
  cin >> practiceTestOne;
  cout << "Practice Test Two: ";
  cin >> practiceTestTwo;

  cout << "Theory Test One: ";
  cin >> theoryTestOne;
  cout << "Theory Test One: ";
  cin >> theoryTestTwo;

  //За да се освободи от изпит на задачи
  //  трябва на двете контролни на задачи да е изкарал поне 4.50 средна оценка, 
  //  като на всяко от контролните му трябва минимум 4.00 
  //  (идеята е че с 3 и 6 не става, с 4 и 5 става)

  if(practiceTestOne >= 4 && practiceTestOne >= 4 && (practiceTestOne*practiceTestTwo)/2 >= 4.5)
  {
    freeOfPractice = true;
  }

  //За да се освободи от изпит на теория
  //  трябва на двете контролни на теория да е изкарал поне 4.50 средна оценка,
  //  като на всяко от контролните му трябва минимум 4.00 
  //  (отново, с 3 и 6 не става, с 4 и 5 става)

  if(theoryTestOne >= 4 && theoryTestTwo >= 4 && theoryTestOne+theoryTestTwo/2 >= 4.5)
  {
    freeOfTheory = true;
  }

  if (!freeOfPractice)
  {
    cout << "Not free of practice exam." << endl;
    cout << "Practice exam: ";
    cin >> practiceExam;
  }

  if (!freeOfTheory)
  {
    cout << "Not free of theory exam." << endl;
    cout << "Theory exam: ";
    cin >> theoryExam;
  }

  if((freeOfPractice || practiceExam >= 3) && (freeOfTheory || theoryExam >= 3) && (hwOne+hwThree+hwThree)/3 >= 3){
    cout << "Shte se pie za uspeha: ";
  }else{
    cout << "Shte se pie ot muka: ";
  }
}