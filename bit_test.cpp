#include <iostream>
#include <bitset>
using namespace std;

// test the bit at a particular position
bool test_bit(unsigned short value, unsigned int position)
{
  // create a bit mask that has 1 at the position and zeros everywhere else
  unsigned short mask = 1 << position;
  //cout << "     Using mask " << bitset<16>(mask) << " to test bit " << position << endl;  

  // AND the mask with the value to test the desired bit
  value &= mask;
  return value;
}

// toggle the bit at a particular position
void toggle_bit(unsigned short& value, unsigned int position)
{
  //cout << "Inital value is " << bitset<16>(value) << endl;

  // create a bit mask that has 1 at the position and zeros everywhere else
  unsigned short mask = 1 << position;
  cout << "     Using mask " << bitset<16>(mask) << " to toggle bit " << position << endl;  

  // XOR the mask with the value to toggle the desired bit
  value ^= mask;
  cout << "   New value is " << bitset<16>(value) << endl;

  return;
}

// Use bitwise operations (set, clear, toggle) to turn a random string into a target string
int main()
{
  // generate random starting and target values
  srand(time(0));
  unsigned short value = rand();
  unsigned short target = rand();
  
  unsigned int position;

  cout << "Starting value is " << bitset<16>(value) << ".\n        Target is " << bitset<16>(target) << ".\nAutomate it!\n";

  // check each bit position and toggle the bit if it does not equal the corresponding target bit
  for(position=0; position<16; position++)
  {
    // if this bit doesn't equal the target bit, toggle it
    if(test_bit(value, position) != test_bit(target, position)){
      toggle_bit(value, position);
      cout << "      Target is " << bitset<16>(target) << endl;
    }
  }// end for

  cout << "Congratulations, you have reached the target.\n";
  return 0;
}
