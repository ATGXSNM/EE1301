#include <iostream>
#include <string>
using namespace std;

int main()
{
        int dollars, cents;
	char temp;
	int d20=0, d10=0, d5=0, d1=0, q=0, d=0, n=0, p=0;

	cout << "How much money do you want? ";

	cin >> dollars >> temp >> cents;   // ignoring the decimal point

	int centsLeft = dollars*100 + cents;
	
	//cout << "You request " << centsLeft << " amount of cents\n";
	
	if(centsLeft >= 2000) // 20 dollar bills
	{
		d20 = centsLeft/2000;
		centsLeft = centsLeft%2000;
	}	
	if (centsLeft >= 1000) // 10 dollar bills
	{
		d10 = centsLeft/1000;
		centsLeft = centsLeft%1000;
	}
	if (centsLeft >= 500) // 5 dollar bills
	{
		d5 = centsLeft/500;
		centsLeft = centsLeft%500;
	}
	if (centsLeft >= 100) // 1 dollar bills
	{
		d1 = centsLeft/100;
		centsLeft = centsLeft%100;
	}
	if (centsLeft >= 25) // quarters
	{
		q = centsLeft/25;
		centsLeft = centsLeft%25;
	}
	if (centsLeft >= 10) // dimes
	{
		d = centsLeft/10;
		centsLeft = centsLeft%10;
	}
	if (centsLeft >= 5) // nickels
	{
		n = centsLeft/5;
		centsLeft = centsLeft%5;
	}
	if (centsLeft >= 1) // pennies
	{
		p = centsLeft;
	}
	
	cout << "Dispensing cash:\n";
	cout << d20 << " $20s\n";
	cout << d10 << " $10s\n";
	cout << d5 << " $5s\n";
	cout << d1 << " $1s\n";
	cout << q << " quarters\n";
	cout << d << " $dimes\n";
	cout << n << " $nickels\n";
	cout << p << " pennies\n";
	return 0;
}





















/*
int main()
{
	int amount; // in cents
	int d20=0, d10=0, d5=0, d1=0, q=0, d=0, n=0, p=0; // amount note denominations
	//double requested;
	int dollars, cents;
	char temp;
	cout << "How much money do you wish to withdraw?\n";
	//cin >> requested;
	cin >> dollars >> temp >> cents;
	//amount = 100*requested; // 18.75 it will convert to 1875
	amount = dollars* 100 + cents;
	
	
	if(amount >= 2000)
	{
		d20 = amount / 2000;
		//amount = amount - d20 * 2000;
		amount -= d20*2000;
	}
	if(amount >= 1000)
	{
		d10 = amount / 1000;
		//amount = amount - d20 * 2000;
		amount -= d10*1000;
	}
	if(amount >= 500)
	{
		d5 = amount / 500;
		//amount = amount - d20 * 2000;
		amount -= d5*500;
	}
	if(amount >= 100)
	{
		d1 = amount / 100;
		//amount = amount - d20 * 2000;
		amount -= d1*100;
	}
	if(amount >= 25)
	{
		q = amount / 25;
		//amount = amount - d20 * 2000;
		amount -= q*25;
	}
	if(amount >= 10)
	{
		d = amount / 10;
		//amount = amount - d20 * 2000;
		amount -= d*10;
	}
	if(amount >= 5)
	{
		n = amount / 5;
		//amount = amount - d20 * 2000;
		amount -= n*5;
	}
	if(amount >= 1)
	{
		p = amount / 1;
		//amount = amount - d20 * 2000;
		amount -= p*1;
	}
	
	cout << "Your change is: \n";
	cout << d20 << " $20 bills\n";
	cout << d10 << " $10 bills\n";
	cout << d5 << " $5 bills\n";
	cout << d1 << " $1 bills\n";
	cout << q << " quarters\n";
	cout << d << " dimes\n";
	cout << n << " nickels\n";
	cout << p << " pennies\n";
		
	
	return 0;
}
*/	
