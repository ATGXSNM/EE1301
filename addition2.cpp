#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double add(double x, double y)
{
	return x+y;
}

int main()
{
	cout << "Enter two numbers to add: ";
	double x;
	double y;
	cin >> x >> y;
	cout << "Their sum is "; 
	cout << add(x,y) << endl;
	
	return 0;
}	


