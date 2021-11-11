#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int N)
{
  int sqrtN = sqrt(N);

  for(int D=2; D<=sqrtN; D++){
    if(N % D == 0){
      // N is divisible by D --> N is not prime
      return false;
    }
  }
  // Checked all possibile divisors and found none --> N is prime
  return true;
}

int main()
{
  // Print the first k primes
  int k;
  cout << "How many primes do you want? ";
  cin >> k;

  int i=2; // first possible prime
  while(k > 0){
    if( isPrime(i) ){
      cout << i << endl;
      k--;
    }
    i++;
  }

  // Print all primes less than 1000 to primes_1000.txt
  ofstream fout;
  fout.open("primes100.txt");
  if(!fout.is_open()){
    cout << "Could not open primes100.txt\n";
    return 1;
  }

  for(int N=2; N<100; N++){
    // if N is prime, print it
    if( isPrime(N) ){
      fout << N << endl;
    }
  }

  fout.close();

  return 0;
}
