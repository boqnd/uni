#include<iostream>

using namespace std;

/*
Годината е 2042. Валери Божинов се доказа, като истински професионалист във всеки
 футболен аспект и в момента е шеф на БФС. Това естествено дава очакваните резултати
  и грандовете Партизан(Червен бряг), Оборище(Панагюрище) и Спартак(Плевен) стигат четвъртфинал Лига Европа.
   След преговори с Пеп Гуардиола (включващи чекмеджето на Борисов и 90 литра сливова отлежала)
    се съгласил да поеме отбора на Миньор(Перник) и стигат до финал в Шампионска лига,
     който печелят с 4-1 срещу състава на Спартак(Москва) благодарение на стратегията на
      Крушарски от 2020 - "Ше ги напием да не могат да играят". Същевременно националният
       отбор воден от 97 годишния стратег от Мировяне - Димитър Пенев е на път да се класира
        за Световното в Судан, но в редовното време и продълженията резултата остава 0-0 и се
         стига до дузпи. Треньорът трябва да избере кой от тримата му вратари да спасява дузпи.
          Вратата има 5 зони (горе ляво, долу ляво, горе дясно, долу дясно и центъра).
           Димитър Пенев има статистически данни за това къде най често бият футболистите
            на Судан и в коя зона би се хвърлил вратаря при всяка дузпа. За съжаление от
             ФИФА забраниха на треньорите да говорят с отбора преди дуспи и той не може
              да каже на своите вратари, къде да се хвърлят, но може да избере кой вратар
               да застане на голлинията. Напишете програма, която по: Въведени имена на вратарите
                - символен низ, Въведени зони къде би се хвърлил вратаря при всяка дузпа
                 - масив от цели числа (зоните), Въведени зони в коя зона биха били дузпите
                  футболистите на Судан, ще отпечата името на вратаря, който според Димитър
                   Пенев ще може да спаси най-много дузпи и да помогне на България да се
                    класира на Световно.
    Пример Вход: Vladislav Stoyanov 5 3 3 2 1 Georgi Petkov 4 4 4 1 2 Cosmin Moti 3512454121
    Изход: Vladislav Stoyanov
      Обяснение: При тази конфигурация Владо Стоянов би спасил 3 дузпи,
       Петков би спасил 1 дузпа, Моци би спасил 2 дузпи. Следователно Владо Стоянов е най-подходящ.
*/

const int MAX_SIZE = 100;


int main(){
  char goalkeeperOne[MAX_SIZE], goalkeeperTwo[MAX_SIZE], goalkeeperThree[MAX_SIZE];
  int scheemaOne[5], scheemaTwo[5], scheemaThree[5], enemyScheema[5];

  cout<<"First goalkeeper name: ";
  cin.getline(goalkeeperOne,MAX_SIZE);
  cout<<"First goalkeeper scheema: ";
  cin >> scheemaOne[0] >> scheemaOne[1] >> scheemaOne[2] >> scheemaOne[3] >> scheemaOne[4];

  //Имах някакъв проблем, не знам защо става така, но ако не са два гетлайна не ми дава да вкарам нищо от конзолата.
  //ето така става когато е с един гетлайн -> 
  //  " First goalkeeper name: a
  //    First goalkeeper scheema: 5 3 3 2 1
  //    Second goalkeeper name: Second goalkeeper scheema: ^C⏎ "
  //когато сложа два пъти гет лайн всичко изглежда нормално при мен.
  //
  //  First goalkeeper name: Vladislav Stoyanov
  //  First goalkeeper scheema: 5 3 3 2 1
  //  Second goalkeeper name: Georgi Petkov
  //  Second goalkeeper scheema: 4 4 4 1 2
  //  Third goalkeeper name: Cosmin Moti
  //  Third goalkeeper scheema: 3 5 1 2 4        
  //  Enemy scheema: 5 4 1 2 1
  //  Vladislav Stoyanov
  // 
  // ако знаете какъв е проблема ми кажете моля. :)
  
  cout<<"Second goalkeeper name: ";
  cin.getline(goalkeeperTwo,MAX_SIZE);
  cin.getline(goalkeeperTwo,MAX_SIZE);
  cout<<"Second goalkeeper scheema: ";
  cin >> scheemaTwo[0] >> scheemaTwo[1] >> scheemaTwo[2] >> scheemaTwo[3] >> scheemaTwo[4];

  cout<<"Third goalkeeper name: ";
  cin.getline(goalkeeperThree,MAX_SIZE);
  cin.getline(goalkeeperThree,MAX_SIZE);
  cout<<"Third goalkeeper scheema: ";
  cin >> scheemaThree[0] >> scheemaThree[1] >> scheemaThree[2] >> scheemaThree[3] >> scheemaThree[4];

  cout<<"Enemy scheema: ";
  cin >> enemyScheema[0] >> enemyScheema[1] >> enemyScheema[2] >> enemyScheema[3] >> enemyScheema[4];

  int firstGoalkeeperSaves = 0, secondGoalkeeperSaves = 0, thirdGoalkeeperSaves = 0;

  for (int i = 0; i < 5; i++)
  {
    if (scheemaOne[i] == enemyScheema[i])
    {
      firstGoalkeeperSaves++;
    }

    if (scheemaTwo[i] == enemyScheema[i])
    {
      secondGoalkeeperSaves++;
    }

    if (scheemaThree[i] == enemyScheema[i])
    {
      thirdGoalkeeperSaves++;
    }
  }

  if (firstGoalkeeperSaves > secondGoalkeeperSaves)
  {
    if (firstGoalkeeperSaves > thirdGoalkeeperSaves)
    {
      cout << goalkeeperOne << endl;
    }else{
      cout << goalkeeperThree << endl;
    }
  }else
  {
    if (secondGoalkeeperSaves > thirdGoalkeeperSaves)
    {
      cout << goalkeeperTwo << endl;
    }else{
      cout << goalkeeperThree << endl;
    }    
  }

  return 0;
}