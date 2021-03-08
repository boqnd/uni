#include <iostream>

using namespace std;
const int MAX_SIZE = 10;



void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n){
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      cout << "| " << matrix[i][j] << " ";
    }
    cout << "|" << endl;
  }
}

void taskOne(){
  int n;

  cout << "n = ";
  cin >> n;


  double matrix[MAX_SIZE][MAX_SIZE];

  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      matrix[i][j] = 0;
    }
  }

  cout << "diagonal = ";
  for (int i = 0; i < n; i++) {
    cin >> matrix[i][i];
  }


  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j ++) {
      int x = j+i;
      int y = j;

      if (x < n && y < n) {
        matrix[x][y] = (matrix[x-1][y] + matrix[x][y+1])/2;
        matrix[y][x] = x + matrix[y][x-1];
      }
    }
  }

  printMatrix(matrix,n);
}




// TASK TWO (ne mi stigna vremeto)

// void taskTwo(char* & str){
//   str[0] = 'k';
// }




// TASK THREE (Ne mi stigna vremeto za da dovursha podavaneto na danni. Za testvane - na 92 i 93 red)
void printArr(int arr[], int n){
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

bool found = false;

void thirdTask(int nums[], int size, int curr[], int currSize, int goal){
  for (int i = 0; i < size; i++) {
    if(currSize == 3){
      if(curr[0]*curr[1]*curr[2] == goal && !found){
        found = true;
        cout << "YES";
        cout << "-> "; printArr(curr,currSize);
      }
    }else {
      curr[currSize] = nums[i];

      thirdTask(nums+1, size-1, curr, currSize+1, goal);
    }
  }
}

void taskThree(){
  //CHANGE HERE TO TEST
  int a[] = {5, 2, 1, 10, 3, 1};
  int goal = 6;


  int n = sizeof(a)/sizeof(*a);
  int b[3];
  thirdTask(a, n, b, 0, goal);
  if(!found){
    cout << "NO" << endl;
  }
}


int main(){
  // taskOne();

  taskThree();

  return 0;
}

