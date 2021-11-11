#include <iostream>
#include <string>

using namespace std;


int main()
{
	double x = 3.14159;
	
	double* xptr = (&x);  // stores the address of x (points to x)
	
	*xptr = 3.3333333;
	
	cout << "x is " << x << endl;
	cout << "x is also " << *xptr << endl;
	cout << "x is located at " << xptr << endl;
	cout << "which is the same as " << &x << endl;
	
	return 0;
}




















/*
#include <iostream>
#include <string>


using namespace std;

int main()
{
	int x = 5;  // normal box with a 5 in it
	
	cout << x << endl; // hopefully no surprises...
	cout << &x << endl; // gets the memory address
	
	int *xp;  // box with a link in it (to nowhere right now)
	
	xp = &x; // xp now pointing to x
	cout << "x = " << *xp << "\n";
	
	return 0;
}
*/
