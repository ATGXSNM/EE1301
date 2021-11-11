#include <iostream>
#include <limits>
using namespace std;

double myMax(double a[], int size)
{
  double max = -1e20; // initialize to the min possible value
  for(int i=0; i < size; i++)
  {
    if(a[i] > max){
      max = a[i];
    }
  }
  
  return max;
}

int main()
{
	double n[4] = {1.1, 2.2, 5.5, 9.9};
	int size = sizeof(n)/sizeof(double);

	// print the array
	cout << "Array: ";
	for(int i=0; i<size; i++)
	{
	  cout << n[i] << "\t";
	}
	cout << endl;
	
	// Find the maximum value in the array and print it
	cout << "Max value of the array is " <<  myMax(n, size) << endl;

	
	return 0;
}

