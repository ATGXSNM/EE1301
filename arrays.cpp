#include <iostream>

using namespace std;

// note: partially filled, add, and insert

void addToEnd(int arr[], int &size, int toAdd);
void printArray(int arr[], int &size);
void insert(int arr[], int& size, int valueTOAdd, int where);

int main()
{
	int myArr[1000]; // partially filled
	int at = 0;
	
	addToEnd(myArr, at, 2);
	addToEnd(myArr, at, 6);
	addToEnd(myArr, at, 42);
	
	printArray(myArr, at);

	insert(myArr, at, 9, 1);
	// insert 9 at index 1

	printArray(myArr, at);
	
	return 0;
}

void addToEnd(int arr[], int &size, int toAdd)
{
	arr[size] = toAdd;
	size++;
}

void printArray(int arr[], int &size)
{
	for(int i=0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void insert(int arr[], int& size, int valueTOAdd, int where)
{
	//start at end
	for(int i = size-1; i >= where; i--)
	{
		arr[i+1] = arr[i]; 
	}
	arr[where] = valueTOAdd;
	size++;
}

