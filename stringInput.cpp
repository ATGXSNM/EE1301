#include <iostream>
#include <string>
using namespace std;

int main()
{
	string firstName, motto;

	cout << "What is your first name?\n"; 
	cin >> firstName;
	
	cin.ignore(100000, '\n');

	cout << "What is your motto?\n";
	getline(cin, motto);
	
	cout << "\"" << motto << "\"\n        -"<< firstName << endl;
	return 0;
}



















/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cout << "Enter a sentence: ";
	//cin >> str;
	getline(cin, str);
	
	cout << "You wrote " << str << "\n";
	
	cout << "How much money do you have? ";
	double bucks;
	cin >> bucks;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Formatted cash value: "<< bucks << endl;
	
	return 0;
}
*/
