#include <iostream>
#include <string>
using namespace std;

int main()
{
  double * ptr;
  ptr = new double; // create a double
  *ptr = 10.10;
  
  int x;
  cout << "How many doubles do you want? ";
  cin >> x;
  
  double * array_ptr;
  array_ptr = new double[x];  // an array of x doubles
  array_ptr[0] = 7;

  for(int i=1; i < 7; i++)
  {
    array_ptr[i] = i;
  }
  
  cout << "array_ptr[6] = " << array_ptr[6] << endl;
  
  delete ptr;          // delete one double
  delete[] array_ptr; // delete the entire array of doubles
  
  return 0;
}
















/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x;
	cin >> x;
	int *arr;
	arr= new int[x];
	
	int sum=0;
	for(int i=0; i < x; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i]=tmp;
		sum += tmp;
	}
	cout << sum;
}
*/
