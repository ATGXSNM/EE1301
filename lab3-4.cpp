#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
int main(){
	int n;
	cout << "Enter a positive integer n: ";
	cin >> n;
	
	if (n < 0){
		cout << "Invalid n"<< endl;
		return 0;
	}
	
	double e = 1, x1 = 1, x0 = 1;
	int i = 0;
	
	while (fabs(e) > 0.01){
		
		x0 = x1;
		x1 = ( x0 + (double)n / x0 ) / 2.0;
		e = x1-x0;
		i++;
		cout <<"Iteration " << i << ", the guess is " << x1 << endl;
		
	}
	
	cout << "Final estimate is " << x1 << endl;
	cout << "Exact square root is " << sqrt(n) << endl;
	
	return 0;
}
