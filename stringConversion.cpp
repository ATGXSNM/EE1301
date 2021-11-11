#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() 
{
	string s = "5.02";
	string s2 = "5.20";
	
	cout << (stod(s)+stod(s2)) << endl;
	
	double d = 4;
	string sd = to_string(d);
	cout << sd << endl;
	
	char cstr[] = {'2', '.', '5', '\0'};
	char cstr2[] = {'2', '.', '5', '\0'};
	double dCstr = atof(cstr);
	
	cout << (dCstr+dCstr) << endl;
	
	cout << strcmp(cstr, cstr2) << endl;
}















/*


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() 
{
	char cString[] = "move zig";
	string IMAstring = cString;	
	cout << IMAstring.c_str() << endl;
	// above converts it back to C-String

	char number1[20];
	string number2;
	cin >> number1 >> number2;
	cout << "sum is: " << (atof(number1) + stod(number2)) << endl;
	
	double x = 5.;
	string xString = to_string(x);
	cout << "xString: "<<xString << endl;
	
	strcpy(number1, xString.c_str()); // copy 5 into number1 (as a string)
	char five[] = "5.000000";
	cout << number1 << endl;
	cout << five << endl;
	cout << "five == number1: "<< (five == number1) << endl;
	cout << "strcmp(five,number1): " << (strcmp(five, number1)==0) << endl;
	
	return 0;
}
*/
