#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int h, change_h,k;
	char c, change_d;
	
	cout <<"Enter current time(A for AM, P for PM): ";
	cin >> h >> c;
	
	cout <<"\nHow many forwards or backwards do you want to move the clock(F for forwards, B for  forwards): ";
	cin >> change_d >> change_h;
	if(change_d == 'F'){
		k = ( h + change_h) % 12;
		if(k % 12 == 0){
			k = 12;
			if(c =='P'){
			c='A';
		}
		else{
			c='P';
		}
	}
		else{
			if((( h + change_h)/12)%2==1){
				if(c=='P'){
					c='A';
				}
				else{
					c='P';
				}
			}
		}
	}
	else{
		k = change_h % 12;
		k = abs(k-h);
		if(c=='A'){
			h = h + 24;
			h = h - change_h;
			if(h>12){
				c='P';
			}
			else{
				c = 'A';
			}
		}
	}
	cout << k <<" "<<c<<"M";
}
		
