#include <iostream>
using namespace std;

int main()
{
	int x[3] = {1, 5, 7};
	
	cout << "The size of an int is " << sizeof(int) << " bytes" << endl;
	cout << "The size of the array is " << sizeof(x) << " bytes" << endl;

	int length = sizeof(x)/sizeof(int);
	cout << "The length of the array is " << length << endl;


	cout << "x is at address: \t"<< x << endl;
	cout << "x[0] is at address: \t"<< &x[0] << endl;
	cout << "x[1] is at address: \t"<< &x[1] << endl;
	cout << "x[2] is at address: \t"<< &x[2] << endl;

	cout << "x[2] is at address: \t"<< x+2 << endl;

	for(int i=0; i < length; i++)
	{
		cout << "x["<<i<<"] is " << x[i] << endl;
	}
	
	return 0;
}

