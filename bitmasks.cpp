#include <iostream>
#include <bitset>
using namespace std;

// set the bit at a particular position
void set_bit(unsigned short& value, unsigned int position)
{
  cout << "Inital value is " << bitset<16>(value) << endl;

  // create a bit mask that has 1 at the position and zeros everywhere else
  unsigned short mask = 1 << position;
  cout << "     Using mask " << bitset<16>(mask) << " to set bit " << position << endl;  

  // OR the mask with the value to set the desired bit
  value |= mask;
  cout << "   New value is " << bitset<16>(value) << endl;

  return;
}

// clear the bit at a particular position
void clear_bit(unsigned short& value, unsigned int position)
{
  cout << "Inital value is " << bitset<16>(value) << endl;

  // create a bit mask that has 0 at the position and ones everywhere else
  unsigned short mask = ~(1 << position);
  cout << "     Using mask " << bitset<16>(mask) << " to clear bit " << position << endl;  

  // AND the mask with the value to clear the desired bit
  value &= mask;
  cout << "   New value is " << bitset<16>(value) << endl;

  return;
}

// toggle the bit at a particular position
void toggle_bit(unsigned short& value, unsigned int position)
{
  cout << "Inital value is " << bitset<16>(value) << endl;

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
  
  char op;
  unsigned int position;

  cout << "Starting value is " << bitset<16>(value) << ".\n        Target is " << bitset<16>(target) << ".\nGo get it!\n";

  // keep modifying the value until it equals the target
  while(value != target)
  {
    cout << "(S)et, (C)lear, or (T)oggle which bit?: ";
    cin >> op >> position;

    if(position < 16)
    {
      switch(op)
      {
        case 'S':
        case 's':
	  set_bit(value,position);
	  break;
        case 'C':
        case 'c':
	  clear_bit(value,position);
	  break;
        case 'T':
        case 't':
	  toggle_bit(value,position);
	  break;
        default:
	  cout << "Invalid operation\n";
      }// end switch
      cout << "      Target is " << bitset<16>(target) << endl;
    }// end if
  }// end while

  cout << "Congratulations, you have reached the target.\n";
  return 0;
}
