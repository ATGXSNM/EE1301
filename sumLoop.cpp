#include <iostream>
using namespace std;

int main() 
{
	int sum = 0;

	int x;
	do
	{		
		cout << "Enter a number: ";
		
		cin >> x;
		sum += x;		
	}while (x != 0);  // 0 is the sentinel value
	
	cout << "Sum was "<<sum<<endl;
	return 0;
}
	











/*
int main()
{
	char response;
	do
	{
		cout << "Enter a number: ";
		
		int x;
		cin >> x;
		sum += x;

		cout << "Do you want to add another number? (y/n) ";	
		cin >> response;
	}while (response != 'n');
	
	
	cout << "Sum was "<<sum<<endl;
	return 0;
}
*/











/*
int main() 
{
	//char choice;
	int sum=0;
	int next;
	cout << "Enter integers to sum separated by spaces (use 0 to exit):\n";
	do
	{
		cin >> next;
		sum+= next;
	 }while(next != 0);
	
	cout << "The sum is: "<<sum<<endl;
	return 0;
	
}
*/
