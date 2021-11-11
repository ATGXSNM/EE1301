#include <iostream>
using namespace std;

int main() 
{
        int i=0;
	while(1) // this loop would run forever 
	{

		if(i == 5000000)
		{
			break; 
		}
		cout << i << endl;
		i++;
		
	}
	cout << "Reached the end of the loop" << endl;
	
	return 0;
}














/*
int main() 
{
	//for(int i=0; i < 10; i++)
	int i=0;
	while(i < 10)
	{
		if(i == 5)
		{
			break; // go directly to the end of the loop
		}
		cout << i << endl;
		i++;
	}
	return 0;
}
*/
