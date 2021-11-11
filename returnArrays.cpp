#include <iostream>
#include <string>
using namespace std;

int* makeFib(int n)
{
  n = max(1,n);
  int* result = new int[n];
  
  //result[0] = n;
  if(n > 0)
  {
    result[0] = 0;
  }
  if(n > 1)
  {
    result[1] = 1;
  }
  for(int i=2; i < n; i++)
  {
    result[i] = result[i-1] + result[i-2];
  }
  
  return result;
}

int main()
{
  int n;
  cout << "How many Fibonacci numbers do you want? ";
  cin >> n;
  
  int* arr = makeFib(n);
	
  for(int i=0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  delete [] arr;
  
  return 0;
}
