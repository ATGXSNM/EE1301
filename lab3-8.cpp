#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	
	cout << "Please enter a positive integer: ";
	cin >> n;
	
	int i ;
	int k = 0;
	
	for (i = 2; i <= sqrt(n); i ++){
		if (k == 0 && n % i ==0){
			cout << n << " = " << i;
			n /= i;
			k = 1;
		}
		while ( n% i == 0){
			cout << " * "<< i;
			n /= i;
		}
	}
	return 0;
}
