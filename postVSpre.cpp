#include <iostream>
using namespace std;

int main()
{
  int x, y, z;

  x = 0;

  y = x++;  // post-increment
  z = ++x;  // pre-increment

  cout << "y = " << y << endl;
  cout << "z = " << z << endl;
  
}
