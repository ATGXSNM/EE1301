#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(){
	double Ti, Ts, T, k, dt, t;
	
	cout <<"Enter the initial temperature :" << endl;
	cin >> Ti;
	cout <<"Enter the temperature of surrounding :" << endl;
	cin >> Ts;
	cout <<"Enter the growth(decay) rate :" << endl;
	cin >> k;
	cout <<"Enter the time step in hours :" << endl;
	cin >> dt;
	cout <<"Enter the simulation length in hours :" << endl;
	cin >> t;
	
	int len = round(t/dt);
	double ti = 0;
	int i = 0;
	while(i < len){
		T = Ti + k*(Ts-Ti)*dt;
		cout << fixed;
		ti = ti + dt;
		cout << setprecision(6) << ti << " " << setprecision(6) << T << endl;
		Ti = T;
		i ++;
	}
	return 0;
}
