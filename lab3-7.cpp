#include <iostream>

using namespace std;

int main(){
	int n, reverse = 0, digit;
	
	cout << "Input a positive integer: " << endl;
	cin>>n;
	
	while(n>0){
		digit = n % 10;
		reverse = (reverse * 10 ) + digit;
		n = n / 10;
	}
	cout << " Reversed: " << reverse;
	return 0;
}
