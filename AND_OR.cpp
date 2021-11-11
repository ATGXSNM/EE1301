#include <iostream>
#include bitset>
using namespace std;

int main()
{

  // Store data in MEMORY
  int X = 0b01010101;
  int Y = 0b11001100;

  // Load data, perform AND instruction, store result to memory
  int X_and_Y = X & Y;

  // Load data, perform OR instruction, store result to memory
  int X_or_Y = X | Y;

  // Write the results
  cout << "X AND Y = " << bitset<8>(X_and_Y) << endl;
  cout << "X OR Y = " << bitset<8>(X_or_Y) << endl;

  return 0;
}
