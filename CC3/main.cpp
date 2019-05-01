#include "Mouchard.h"

using namespace std; 

int main() {
  
  Int* p = (Int*) ::operator new(4 * sizeof(Int));

  Int* i1 = (Int*) ::operator new(sizeof(Int));
  
  i1 = new Int();
  
  Int* i2 = (Int*) ::operator new(sizeof(Int));
  
  i2 = new Int(5);
  
  Int* i3 = (Int*) ::operator new(4 * sizeof(Int));
  i3 = new Int(*i2);
  
  Int* i4 = (Int*) ::operator new(4 * sizeof(Int));
  i4 = new Int(move(*i3));
  
  *i1 = *i4;
  
  *i1 = move(*i4);
  
  delete i4;
  
  delete i3;
  
  delete i2;
 
  delete i1;
  
  ::operator delete(p);
}