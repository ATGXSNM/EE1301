#include <iostream>
using namespace std;

void sillySwap(int x, int y)
{	
	int temp;
	temp=x;
	x=y;
	y=temp;
}

int main()
{
	int a = 7, b = 11;
	
	cout<<"Before swap, a = "<<a<<", b = "<<b<<endl;

	sillySwap(a,b);
	
	cout<<"After swap,  a = "<<a<<", b = "<<b<<endl;
	
	return 0;
} 
