#include <iostream>
using namespace std;

int main()
{
	int integer;
	long longInteger;
	cout << "Enter a number for the int: ";
	cin >> integer;
	
	cout << "Enter a number for the long: ";
	cin >> longInteger;
	
	cout << "Your integer " << integer << " occupies " << sizeof(int) << " bytes\n" 
	     << "Your long " << longInteger << " occupies " << sizeof(long) << " bytes\n";
	
	
	bool isItRaining = false;
	return 0;
}
























/*
#include <iostream>

using namespace std;

int main()
{
	int imaINT;
	long imaLONG;
	
	cout << "Enter a number (int):\n";
	cin >> imaINT;
	cout << "You entered: " << imaINT << "\n";

	cout << "Enter a number (long):\n";
	cin >> imaLONG;
	cout << "You entered: " << imaLONG << endl;
	
	
}

*/
