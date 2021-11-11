#include <iostream>
using namespace std;

int main() 
{
	const int size = 5;
	double array[size] = {1.404, 2.35, 3.14, 4.04, 5.55};
	double sum = 0.0;
	
	//sum = x[0] + x[1] + x[2] + x[3] + x[4]; // this would work, but there is an easier way

	for(int i=0; i < size; i++)
	{
		sum += array[i];
	} 
	
	cout << "Average is: " << sum/size << endl;

	return 0;
}



















/*
int main()
{
	//int x[] = {1, 2, 3, 4, 5};
	int x[10] = {1, 2, 3, 4, 5}; // missing elements initialized to 0
	
	int sum =0;
	for(int i=0; i < 5; i++)
	{
		sum += x[i];
	}
	
	cout << "Average is " << sum/5.0 << endl;
	
	return 0;
}
*/
