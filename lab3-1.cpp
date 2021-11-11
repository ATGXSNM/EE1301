#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, c, t1 = 0, t2 = 1, next;
	cout << " Enter the number of Fibonacci series you want: " << endl;
	cin >> n;
	
	cout << " Fibonacci series : "<< n << endl;;
	
	for ( c = 0; c <= n ; c++){
		
		if ( c <= 1){
			next = c;
		}else{
			next = t1 + t2;
			t1 = t2;
			t2 = next;
			}
			cout << next << " " << endl;;
		}
		return 0;
}
