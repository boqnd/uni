#include <iostream>
#include <string>

using namespace std;
/*
Задача 1

Да се напише функция, която приема масив от низове, като се създава хистограма (честотна таблица), която показва колко пъти се среща всеки низ.

Вход: (това са подадените параметри на функцията и върната от тях стойност) ["hello", "world", "hello", "hello", "bye", "world", "hello"] Изход: 4 - hello 2 - world 1 - bye

Упътване: напишете свой strcmp, не използвайте готовия. Директно във функцията да се отпечатва хистограмата.

Задача 2

Напишете функция, която приема символен низ и връща указател към най дългата дума в него. Ако има няколко такива функцията да връща указател към първата такава.

Задача 3

Да се напише рекурсивна функция, която по подаден масив от цели числа(0-9) и неговия размер, връща стойност определена по следния начин. Ако числото е между 4 и 7 го добавяме към тази стойност, ако числото е между 1 и 3 го изваждаме от тази стойност, ако е 8, 9 или 0 прекратяваме рекурсията

Пример: (това са подадените параметри на функцията) Вход: масив -> [7, 3, 5, 6, 2, 1, 7, 3, 9, 6, 4] размер -> 11 Изход: 16

Забележка: Нямате право да използвате никакви допълнителни променливи
*/


// void FirstTask(char* words[]){

//   size_t size = 0;
//   while (!words[size].empty()){
//     ++size;
//   }

//   string wordColumn[size];
//   int countColumn[size];

//   for(int i = 0; i < size; i++){
//     string word = words[i];
//     bool notFound = true;

//     for(int j = 0; j < size; j++){
//       if(wordColumn[j] == word){
//         countColumn[j]++;
//         notFound = false;
//       }
//     }

//     if(notFound){
//       for(int j = 0; j < size; j++){
//         if(wordColumn[j] == ""){
//           wordColumn[j] = word;
//           countColumn[j] = 1;
//           break;
//         }
//       }
//     }
//   }

//   for(int i = 0; i < size; i++){
//     cout<< wordColumn[i] << " " << countColumn[i] << endl;
//     // if(wordColumn[i] != ""){
//     //   cout << countColumn[i] << " - " << wordColumn[i] << " ";
//     // }else{
//     //   cout << endl;
//     //   break;
//     // }
//   }

// }


bool SameWords (char fstWord[], char scndWord[]){
  bool oneWordEnd = (*fstWord == '\0' && *scndWord != '\0') || 
                    (*fstWord != '\0' && *scndWord == '\0');
                 
  if (oneWordEnd){
    return false;
  }

  if (*fstWord != *scndWord){
    return false;
  }

  if (*fstWord == '\0' && *scndWord == '\0'){
    return true;
  }

  return SameWords(fstWord+1, scndWord+1);
}




void FirstTask(const char** words){
  cout << *(words+2) << endl;


}



void getFirstWord(char* str, char*& result){
  size_t index = 0;
  char curr = *str;
  char word[100];

  while(curr != '\0' && curr != ' '){
    word[index++] = curr;
    curr = *(str+index);
  }


  strcpy(word,result);
}

char* removeFirstWord(char* str){
  size_t index = 0;
  char curr = *str;

  while(curr != '\0' && curr != ' '){
    curr = *(str+(++index));
  }

  return str+(++index);
}

int getWordSize(char* str){
  size_t counter = 0;
  char curr = *str;

  while(curr != '\0'){
    curr = *(str+(++counter));
  }

  return counter;
}

// int getWordIndex(char* str){
//   int index = 0;
//   int curr = getWordSize(getFirstWord(str));
//   int max = 0;

//   if(getWordSize(curr) > getWordSize(max)){
//     max = curr;
//   }
//   str = removeFirstWord(str);
//   curr = getFirstWord(str);

//   curr = curr;
//   cout << max << endl;
//   cout << curr << endl;
// }


void SecondTask(char* str){
  char* curr;
  getFirstWord(str, curr);
  char* max = "";

  // while(getWordSize(curr) > 0){
  //   //cout << curr << endl;
  //  if(getWordSize(curr) > getWordSize(max)){
  //    max = curr;
  //  }
  //   str = removeFirstWord(str);
  //   curr = getFirstWord(str);
  // }

  max = curr;
  cout << max << endl;
  cout << curr << endl;


}

int main(){

  // const char* arr[] = {"aa", "Asdf", "aa"};

  // // FirstTask(arr);

  // char wordTable[][3];
  // int** countTable;


  // *wordTable = arr[0];

  // cout << *wordTable;

  // return 0;


  char* str = "asdf as";

  // SecondTask(str);

  cout << "_____________________________________" << endl << endl;
  SecondTask(str);


  return 0;
}

