#include <iostream>
#include <ctime>
using namespace std;

void makeSpaces(int num) // this will print [num] amount of spaces
{	
	for(int i=0; i<num; i++)
	{
		cout << "   ";
	}
	
	return;
}

int resetScreen()
{
	// hack solution
	for(int i=0; i < 20; i++)
	{
		cout << endl;
	}
	
	return 0;
}

int feetSpread(int spaces)
{
	resetScreen();
	makeSpaces(spaces);
	cout << "    ~\\|/^" << endl; 
	// note you need to use  "\\" to get a single "\" to show up -- this is called an escape character
	makeSpaces(spaces);
	cout << "     (_oo." << endl;
	makeSpaces(spaces);
	cout << "    __+__/`" << endl;
	makeSpaces(spaces);
	cout << "  /   |" << endl;
	makeSpaces(spaces);
	cout << "     /--\\" << endl;
	makeSpaces(spaces);
	cout << "    /    \\" << endl;
	makeSpaces(spaces);
	cout << "   /      |" << endl;
	makeSpaces(spaces);
	cout << "   L      L" << endl;
	return 0;		
}


int feetTogether(int spaces)
{
	resetScreen();
	makeSpaces(spaces);
	cout << "    _\\|/^" << endl;
	makeSpaces(spaces);
	cout << "     (_oo _," << endl;
	makeSpaces(spaces);
	cout << "    /-|--/" << endl;
	makeSpaces(spaces);
	cout << "    ' |" << endl;
	makeSpaces(spaces);
	cout << "     \\-\\" << endl;
	makeSpaces(spaces);
	cout << "     / /" << endl;
	makeSpaces(spaces);
	cout << "     L L" << endl;

	return 0;
}


void sleepz(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


int main()
{
        int steps;
	cout << "How long should he just keep running? ";
	cin >> steps;

	for(int i=0; i<steps;i++)
	{
		feetSpread(i); // show the stride
		sleepz(150000);
		feetTogether(i); // show feet together picture
		sleepz(150000);
	}
}



