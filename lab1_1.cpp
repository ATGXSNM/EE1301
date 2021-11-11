#include <iostream>
using namespace std;



int main(){
	double h;
	int x;
	cout << " Enter the value of x and h: "<< endl;
	cin >> x;
	cin >> h;
	double temp = ((double) x+h);
	double res = ((temp*temp*temp)-(x*x*x))/h;
	cout <<"Derivative of x^3 is : " << res <<endl;
	return 0;
}

