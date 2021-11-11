#include <iostream>
#include <string>
using namespace std;

double maxA(double array[], int size)
{
	if(size == 0)
	{
		return 0.0/0.0;
	}
	double max = array[0];
	
	for(int  i=1; i < size; i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}
	
	return max;
}

double* maxAptr(double* array, int size)
{
	if(size == 0)
	{
		return 0;
	}
	double* max = &(array[0]);
	
	for(int  i=1; i < size; i++)
	{
		if(array[i] > *max)
		{
			max = &(array[i]);
		}
	}
	
	return max;
}

int main()
{
	double x[4] = {2, 2.5, 4, -20.20};
	double mx = maxA(x, 4);
	
	cout << "max (non-pointer version) is " << mx << endl;
	mx = -9999;
	cout << "x[2] is now: " << x[2] << endl;
	
	
	double* mxptr = maxAptr(x, 4);
	cout << "max (pointer version) is " << *mxptr << endl;
	*mxptr = -9999;
	cout << "x[2] is now: " << x[2] << endl;
	return 0;
}























/*

#include <iostream>
#include <string>

using namespace std;

double findMax(double array[], int size);
double* findMaxPtr(double array[], int size);

int main()
{
	double x[] = {1, 2, 3.5, 8, 4, 6, 2, 1};
	int xMax = findMax(x, 8);
	xMax = -9999;
	cout << "x[3] is now: " << x[3] << endl;
	double* maxPtr = findMaxPtr(x, 8);
	*maxPtr = -9999;
	cout << "x[3] is now: " << x[3] << endl;
	
	return 0;
}

double findMax(double array[], int size)
{
	if(size == 0)
	{
		return 0.0/0.0;
	}
	
	double mx = array[0];
	for(int i=1; i < size; i++)
	{
		if(array[i] > mx)
		{
			mx = array[i];
		}
	}
	
	return mx;
}

double* findMaxPtr(double array[], int size)
{
	if(size == 0)
	{
		return nullptr;
	}
	
	double *mx = &(array[0]);
	for(int i=1; i < size; i++)
	{
		if(array[i] > *mx)
		{
			mx = &(array[i]);
		}
	}
	
	return mx;
}

*/
