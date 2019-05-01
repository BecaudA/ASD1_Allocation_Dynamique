#include "Mouchard.h"

using namespace std; 

int main() {
  
  Int i1;
  
  Int i2 = 5;
  
  Int i3 = i2;
  
  Int i4 = move(i3);
  
  i1 = i4;
  
  i1 = move(i4);
}