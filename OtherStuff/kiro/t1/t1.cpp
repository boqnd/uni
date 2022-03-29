#include <iostream>
#include <fstream>
#include <string>


int main() {
  char test = 'a';
  char rt;

  fstream myFile ("data.bin", ios::binary); 

  myFile.write ((char*)&test, sizeof (char)); 
    
  myFile.seekg (0);  

  myFile.read ((char*)rt, sizeof (char)); 
    
  myFile.close(); 

  std::cout << rt << std::endl;

  return 0;
}