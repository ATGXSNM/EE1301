#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double w, h, a, BMR;
	char ch;
	cout<< "Enter input weight in pounds: ";
	cin >> w;
	cout<< "Enter input height in inches: ";
	cin >> h;
	cout<< "Enter input age in years: ";
	cin >> a;
	cout<< "Enter input charater: ";
	cin >> ch;
	
	if(ch=='M'||'m'){
		BMR = 66 + (6.3*w)+(12.9*h) - (6.8*a);
		cout<<"The formula that calculates the calories needed for a man to maintain his weight is :"<< BMR << endl;
	}
	else if(ch == 'F'||'f'){
		BMR = 655+ (4.3*w)+(4.7*h)-(4.7*a);
		cout<<"The formula that calculates the calories needed for a feman to maintain his weight is :"<< BMR << endl;
	}
	else{
		cout << "Invalid operation. Only type F OR M!" << endl;
	}
	
	return 0;
}
