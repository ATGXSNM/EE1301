#include <iostream>

using namespace std;

int main()
{
	int i;
	cout << "How many times do you want to run the loop?\n";
	cin >> i; // what happens if i is less than 1?

	do {
		cout << "Looping, i = " << i << "\n";
		i--;
	} while (i > 0);	
	cout << "After the loop, i = " << i << "\n";
	
	return 0;
}
