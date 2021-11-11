#include <iostream>
#include <string>
using namespace std;

int global = 1; // This variable is visible everywhere in the program

int main()
{
	int x;
	cout << "Enter a number? ";
	cin >> x;
	
	if(x > 0)
	{ // y declared after this brace
		int y;
		cout << "Enter another number: ";
		cin >> y;
		cout << "The sum is " << x+y << endl;

	} // R.I.P. y
	
	if(x > 0)
	{ // a different y declared after this brace
		int y;
		//cout << "Enter another number: ";
		cout << "The other sum is " << x+y << endl;

	} // R.I.P. other y

	return 0;
} // R.I.P. x















/*
	int number;
	cout << "Enter a positive number: ";
	cin >> number;
	if(number > 0)
	{
		cout << "Enter another number: ";
		int number2;
		cin >> number2;
	}
	
	cout << "Their sum is " << number + number2 << endl;
	
	return 0;
}
*/
