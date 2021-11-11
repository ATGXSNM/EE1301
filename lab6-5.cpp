#include <iostream>
using namespace std;

void noRepeat(char x[], int xlen, char y[], int ylen, char z[])
{
int rlen = 0, i, j;
char temp[200];

for(i = 0; i < xlen; i++)
temp[i] = x[i];

for(int j = 0; j < ylen; j++)
temp[i+j] = y[j];

for(int i = 0; i < xlen + ylen ; i++){
	for(j = rlen-1; j >= 0; j--)
	if(temp[i] == z[j])
	break;
	if(j == -1)
	z[rlen++] = temp[i];
	}
	}
int main()
{
char x[] = {'h', 'e', 'l', 'l', 'o', ' '};
char y[] = {'l', 'l', 'a', 'm', 'a'};
char result[200];

noRepeat(x, 6, y, 5, result);

cout << result;

noRepeat(y, 5, x, 6, result);
cout << result;
cout<<endl;
}
