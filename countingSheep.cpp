#include <iostream>
#include <bitset>
using namespace std;

int main()
{
  short x=0;  // a short is 2 bytes long, so there are 2^16 = 64k possible values, 16k +ive and 16k -ive
  while(true)
  {
      cout << x << "  ==  " << bitset<16>(x) << endl;
      x++;

      // delay loop to slow down the printing
      for(int i=0; i<100000; i++){
	int a = 19948*2929;
      }
  }
  
}












/*
int main()
{
	short x=1;
	while (true)
	{
		cout <<"Sheep "<<x<<"...\n";
		x++;
	}
	return 0;
}
*/
