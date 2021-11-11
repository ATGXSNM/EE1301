#include <iostream>
#include <string> // need to include this library to use string
using namespace std;

int main() 
{
	string word = "hello";
	string word2 = " world";
	string word3 = "hello";
	
	string combine = word + word2;
	cout << combine << endl;
	
	cout << combine[2] << endl;
	
	cout << (word == word3) << endl;
	
	cout << "First space is at: " << combine.find(' ') << endl;
	
	cout << "Characters after the space are: " << combine.substr(combine.find(' ')+1) << endl;
}























/*
#include <iostream>
#include <string> // yes, THIS string
using namespace std;

int main() 
{
	string pref = "i like "; // dont need null char, inserted automatically
	string favFood = "anything free";
	string prefCopy = "i like ";
	
	cout << pref + favFood << endl; // concatenate strings
	cout << "pref == prefCopy: " << (pref == prefCopy) << endl;
	cout << "pref[2] = " << pref[2] << endl;
	cout << "pref space at " << pref.find(' ') << endl;
	cout << "pref after space: " << pref.substr( pref.find(' ')+1) << endl;

	// only one above that works for C-Strings is: pref[2]

}
*/
