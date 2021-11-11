#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double babylonianRoot(double n){
	double input = n;
	double value = 1;
	double e = 0.000001;
	while (input - value > e){
		input = (input + value ) / 2;
		value = n / input;
	}
	return input;
}

int main(){
	char choice = 'y';
	double n;
	while(choice == 'y'){
		cout <<"Enter a value:";
		cin >> n;
		cout <<"Square root of " << n << " is " << babylonianRoot(n)<<endl;
		cout << "continue?(y/n):";
		cin >> choice;
	}
	
}
	
