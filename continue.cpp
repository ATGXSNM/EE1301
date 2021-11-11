#include <iostream>
using namespace std;

int main() 
{
        char ans = 'n';
  
	for (int i=0; i<10; i++)
	{
		cout << "Skip this iteration? (y/n) ";
		cin >> ans;
		if(ans == 'y')
		{
			continue; // goto the beginning of the next iteration
		}
		cout << i << endl;  // only gets printed if we choose not to continue
		
	}
	
}














/*
int main() 
{
	int i=0;
	while(i < 10)
	{
		if(i == 5)
		{
			continue; // skip the iteration when i==5
		}
		cout << i << endl;
		i++;
	}
	return 0;
}
*/
