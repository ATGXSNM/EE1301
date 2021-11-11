#include <iostream>
#include <fstream>
using namespace std;

float power(float base, unsigned int exponent)
{
  float result = base;
  for(int i=0; i<exponent-1; i++){
    result *= base;
  }
  return result;
}

int main()
{
  // Print the first N powers of 2
  unsigned int N;
  cout << "How many powers of 2 do you want? ";
  cin >> N;

  for(int i=1; i<=N; i++)
  {
    cout << power(2,i) << endl;
  }

  // Print all powers of 2 less than 10000 to power10000.txt
  ofstream fout;
  fout.open("power10000.txt");
  if(!fout.is_open()){
    cout << "Could not open power10000.txt\n";
    return 1;
  }

  float result;
  unsigned int i = 1;

  do
  {
    result = power(2,i);
    if(result < 10000){
      fout << result << endl;
    }
    i++;
  }while(result < 10000);

  fout.close();

  return 0;
}
