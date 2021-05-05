#include "include/index.h"

int main() {

  Student st;
  st.enroll(72029, "IS", 1)
    .print()
    .interrupt()
    .print()
    .resume()
    .advance()
    .graduate()
    .print();
  
  return 0;
}

