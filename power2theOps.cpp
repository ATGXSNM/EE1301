#include <iostream>
#include <bitset>
using namespace std;

// compare general-purpose and bitwise versions of different operations for power of 2 operands
int main()
{
  // compare GP and bitwise multiplication
  cout << "Multiplying 10 * 4096\n";
  cout << "   with normal mult: 10 * 4096 = " << 10*4096 << endl;
  cout << "   with bit shift:    10 << 12 = " << (10 << 12) << endl;  
  cout << "Now in binary: " << bitset<16>(10) << " * " << bitset<16>(4096) << " =  " << bitset<16>(10<<12) << endl << endl;

  // compare GP and bitwise division
  cout << "Dividing 39488 / 32\n";
  cout << "   with normal div: 39488 / 32 = " << 39488/32 << endl;
  cout << "   with bit shift:  39488 >> 5 = " << (39488 >> 5) << endl;  
  cout << "Now in binary: " << bitset<16>(39488) << " / " << bitset<16>(32) << " =  " << bitset<16>(39488>>5) << endl << endl;

  // compare GP and bitwise modulus
  cout << "Taking 1034 % 256\n";
  cout << "   with normal mod: 1034 % 256 = " << 1034%256 << endl;
  cout << "   with AND:        1034 & 255 = " << (1034 & 255) << endl;  
  cout << "Now in binary: " << bitset<16>(1034) << " % " << bitset<16>(256) << " =  " << bitset<16>(1034) << " & " << bitset<16>(255) << " = " << bitset<16>(1034&255) << endl;

  return 0;
}
