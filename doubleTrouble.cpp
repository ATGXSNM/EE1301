#include <iostream>
#include <string>

using namespace std;

int main(){
	
	if( (0.1 + 0.2) == 0.3)
	{
	  cout << "No double trouble. Phew." << endl;
	}
	else
	{
	  cout << "DOUBLE TROUBLE!" << endl;
	}
	
	string name = "John Jacob Jingleheimerschmidt";
	string name2 = "John Jacob Jingleheimerschmidt";
	
	if(name.compare(name2) == 0)
	{
	  cout << "His name is my name too!\n";
	}
	else
	{
	  cout << "The names are different.";
	}
	
	return 0;
}






















/*
#include <iostream>

using namespace std;

int main()
{
	if (0.1 + 0.2 == 0.3)
	{
		cout << "Computer is smart!\n";
	}
	else
	{
		cout << "Umm... no.\n";
	}
	
	return 0;
}
*/
