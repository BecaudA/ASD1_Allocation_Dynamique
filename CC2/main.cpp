#include "Mouchard.h"

using namespace std; 

int main() {
   
  Int* i1 = new Int();
  
  Int* i2 = new Int(5);
  
  Int* i3 = new Int(*i2);
  
  Int* i4 = new Int(move(*i3));
  
  *i1 = *i4;
  
  *i1 = move(*i4);
  
  delete i4;
  
  delete i3;
  
  delete i2;
 
  delete i1;
}