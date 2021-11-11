#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ITERS 40000000

// compare the performance of general-purpose and bitwise versions of different operations for power of 2 operands
int main()
{
  volatile int result;
  int op2, power;
  int i;
  clock_t ticks, GPmult, BWmult, GPdiv, BWdiv, GPmod, BWmod;

  srand(time(NULL));
  // second operand will be a power of 2
  power = rand()%16;
  op2 = 1 << power;

  // compare GP and bitwise multiplication
  result = 1;
  ticks = clock();
  for(i=0; i<ITERS; i++){
    result *= op2;
  }
  GPmult = clock()-ticks;
  //cout << "GP mult result: " << result << endl;
  cout << "GP mult time: " << GPmult << endl;

  result = 1;
  ticks = clock();
  for(i=0; i<ITERS; i++){
    result <<= power;
  }
  BWmult = clock()-ticks;
  //cout << "BW mult result: " << result << endl;
  cout << "BW mult time: " << BWmult << endl;

  // compare GP and bitwise division
  result = 2147483647;
  ticks = clock();
  for(i=0; i<ITERS; i++){
    result /= op2;
  }
  GPdiv = clock()-ticks;
  //cout << "GP div result: " << result << endl;
  cout << "GP div time: " << GPdiv << endl;

  result = 2147483647;
  ticks = clock();
  for(i=0; i<ITERS; i++){
    result >>= power;
  }
  BWdiv = clock()-ticks;
  //cout << "BW div result: " << result << endl;
  cout << "BW div time: " << BWdiv << endl;

  // compare GP and bitwise modulus
  result = 2147483647;
  ticks = clock();
  for(i=0; i<ITERS; i++){
    result %= op2;
  }
  GPmod = clock()-ticks;
  //cout << "GP mod result: " << result << endl;
  cout << "GP mod time: " << GPmod << endl;

  result = 2147483647;
  ticks = clock();
  for(i=0; i<ITERS; i++){
    result &= (op2-1);
  }
  BWmod = clock()-ticks;
  //cout << "BW mod result: " << result << endl;
  cout << "BW mod time: " << BWmod << endl;

  cout << "Speedup of BWmult over GPmult: " << double(GPmult)/BWmult << endl;
  cout << "Speedup of BWdiv over GPdiv: " << double(GPdiv)/BWdiv << endl;
  cout << "Speedup of BWmod over GPmod: " << double(GPmod)/BWmod << endl;

  return 0;
}
