#include <iostream>
#include <math.h>

using namespace std;

int main(){
	
	double L, v, Lr;
	double c = 3e10;
	cout <<"Enter the value of Length: " << endl;
	cin >> L;
	cout << "Enter the value of velocity: " << endl;
	cin>>v;
	
	Lr = L * sqrt(1 - (pow(v, 2) / pow(c,2)));
	cout << pow(v, 2) / pow(c,2) <<endl;
	cout << 1 + 4 / 2 << endl;
	cout << Lr << endl;

}
