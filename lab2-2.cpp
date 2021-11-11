#include <iostream>

using namespace std;

int main(){
	double temp, res;
	char ch;
	cout <<"Enter the temperature: " << endl;
	cin >> temp;
	cout << "Enter Celsius(c) or Fahrenheit(f)" << endl;
	cin>>ch;
	
	if(ch=='c'){
		res = temp*(9.0/5.0)+32.0;
		cout<<"The temperature in Celsius: " << res << endl;
	}
	else{
		res = (temp-32.0)*(5.0/9.0);
		cout<<"The temperature in Fahrenheit: " << res << endl;
	}
	return 0;
}
