#include <iostream>
#include <string>
using namespace std;

int main()
{
	int controlingVariable;
	cout << "Enter a number: ";
	cin >> controlingVariable;
	
	cout << "\nwith switch\n";

	switch(controlingVariable)
	{
		case 2: // if(controlingVariable == 2)
		case 4:
			cout << "controllingVariable is either 2 or 4" << endl;
			break;
		case 3:
			cout << "controllingVariable is 3\n";
			break;
		default:
			cout << "controllingVariable is not 2, 3 or 4...\n";
			break;
	}

	cout << "\nwith if/else:\n";

	if(controlingVariable == 2 || controlingVariable == 4){
	  cout << "controllingVariable is either 2 or 4" << endl;	  
	} else if(controlingVariable == 3){
	  cout << "controllingVariable is 3\n";
	} else{
	  cout << "controllingVariable is not 2, 3 or 4...\n";
	}
}
