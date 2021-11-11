#include <iostream>

using namespace std;

int main(){
	
// a
	double *d_var, *d_array;

// b
	double c = double(1);
	d_var = &c;
	d_array = new double[10];

// c
	cin >> *d_var;
	cout << *d_var<< endl;

// d
	for(int i = 0; i < 10; i++){
	*(d_array + i) = 1.0;
	}

	for(int i = 0; i < 10; i++){
	cout << *(d_array + i) << " ";
	}
	cout << endl;

//e
	delete [] d_array;

	return 0;
}
