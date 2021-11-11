#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> x;	
//	vector<double> nums;
	
	x.push_back("first");
	x.push_back("second");
	x.push_back("third");
	// adds an item to the end of the array

	for(int i=0; i < x.size(); i++)
	{             // size() tells how many in the array
		cout << x[i] << ", ";
		// use as normal array
	}
	cout << endl;
	
	x.insert(x.begin()+1, "cutting in line!");

	for(int i=0; i < x.size(); i++)
	{             // size() tells how many in the array
		cout << x[i] << ", ";
		// use as normal array
	}
	cout << endl;
	
	// remove uses erase()
	x.erase(x.begin()+0);
	
	for(int i=0; i < x.size(); i++)
	{             // size() tells how many in the array
		cout << x[i] << ", ";
		// use as normal array
	}
	cout << endl;
	
	

	return 0;
}

















/*
int main()
{
	vector<string> names;
	names.push_back("first");	
	names.push_back("second");	
	names.push_back("third");
	
	for(int i=0; i < names.size(); i++)
	{
		cout << names[i] << ", ";
	}
	cout << endl;
	
	names.insert(names.begin()+1, "cutting in");
	

	for(int i=0; i < names.size(); i++)
	{
		cout << names[i] << ", ";
	}
	cout << endl;
	
	return 0;
}
*/
