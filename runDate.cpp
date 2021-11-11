#include <iostream>
using namespace std;
#include "dateClass.h"  // using the date class defined in this file

int main()
{
  date newyears;
  
  // use constructor to initialize today's date
  newyears = date(1,1,2017);

  // another way to call the constructor
  date cinco(5, 5, 2016);
  
  cout << "New years is: ";
  newyears.print();
  cout << endl;

  cout << "Cinco de mayo es: ";
  cinco.print();
  cout << endl;

  return 0;
  
}
