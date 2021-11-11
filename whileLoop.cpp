#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	while (i < 5)
	{
		cout << "Looping, i = " << i << "\n";
		i++;
	}
	cout << "After the while loop, i = " << i << "\n";
	
	for(i=0; i <10; i++)
	{
		cout << "Looping, i = " << i << "\n";
	}
	cout << "After the for loop, i = " << i << "\n";
	
	return 0;
}
