#include <iostream>
using namespace std;

int main() 
{
	int beerCount = 99;
	while(beerCount > 0)
	{
		cout << beerCount << " bottles of beer on the wall, "<<beerCount<<" bottles of beer!\n";
		beerCount--;
		cout << "Take one down.  Pass it around.  "<<beerCount<<" bottles of beer on the wall.\n\n";
		//beerCount--;
	}
	
	return 0;
}
