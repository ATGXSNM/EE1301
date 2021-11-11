#include <iostream>
using namespace std;

int main() 
{

	int cents;
	int smartyCount =0, dumdumsCount=0;
	int smartyCost= 100, dumdumsCost=59;
	char button;
	cout << "WELCOME to candytron 1301!\n";
	cout << "Your options are:"<<endl;
	cout << "(s)marties for "<<smartyCost<<" cents\n";
	cout << "(d)um dums for "<<dumdumsCost<<" cents\n";
	
	cout << "Insert coins please...\n";
	cin >> cents;
	
	do
	{
		cout << "Press (s) for smarties, (d) for dum dums or (q) to quit\n";
		cin >> button;
	
		if(button == 's' && cents >= smartyCost)
		{
			cout << "You bought smarties.";
			cents -= smartyCost;
			smartyCount++;
			cout <<"  You have "<<cents<<" cents left.\n";			
		}
		else if (button == 's')
		{
			cout << "You need "<<smartyCost<<" cents to buy smarties. Have your "<< cents << " cents back.\n";		
		}	
		else if (button == 'd')
		{
			if(cents >= dumdumsCost)
			{
				cout << "You bought a dum dum.";
				cents -= dumdumsCost;
				dumdumsCount++;
				cout <<"  You have "<<cents<<" cents left.\n";			
			}
			else
			{
			  cout << "You need "<<dumdumsCost<<" cents to buy dum dums. You only had "<< cents << " cents.\n";
			}
		}
		else if (button == 'q')
		{
			break;
		}
		else if (button != 'q')
		{
			cout << "Since you can't follow hte instructions, I am keeping your money.\n";
		}
	}while(true); // use a break to stop
	//}while (button != 'q'); // end loop
	
	cout << "You walk away with "<<smartyCount<<" smarties, "<<dumdumsCount<<" dum dums and "<<cents<<" cents.\n";
	return 0;
}




















/*
#include <iostream>
using namespace std;

int main()
{

	int amount;
	int smartiesCount=0,dumdumCount=0;
	cout << "WELCOME to the smarties 'n' dum dums vendor-tron 1301\n";
	cout << "Option 's': smarties for 10 cents\n";
	cout << "Option 'd': dum dums for 59 cents\n";
	cout << "Please insert coins: ";
	cin >> amount;
	
	char choice = 'a';
	while(choice != 'q')
	{
	cout << "You have "<<amount<< " cents remaining.\n";
	cout << "Please press 's' for smarties, 'd' for dum dums or 'q' to quit: \n";
	cin >> choice;
	
	
		if(choice == 's')
		{
			if(amount >= 10)
			{
				amount -= 10;
				smartiesCount ++;
			cout << "You purchase a smarties.\n";
			}
			else
			{
				cout << "Insufficient funds to purchase smarties.\n";
			}
		}
		else if(choice == 'd')
		{
			if(amount >= 59)
			{
				amount -= 59;
				dumdumCount++;
				cout << "You purchase a dum dum.\n";
			}
			else
			{
				cout << "Insufficient funds to purchase dum dums.\n";
			}
		}
		else if (choice != 'q')
		{
			cout << "Learn to read instructions, human.  I am keeping your money for wasting my time.\n";
			choice = 'q';
		}
	}
	
	cout << "You walk away with "<<smartiesCount<<" smarties, "<<dumdumCount<<" dum dums and "<<amount<<" cents.\n";
	
	return 0;
}
*/

