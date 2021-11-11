#include <iostream>
#include <string>
using namespace std; 

int main(){
	string p1,p2;
	int ph1, ph2;
	
	cout <<"Partner 1's full name";
	cin >> p1;
	cout <<"Partner 1's height(imaginary friend)";
	cin >> ph1;
	cout <<"Partner 2's full name";
	cin >> p2;
	cout <<"Partner 2's height(imaginary friend)";
	cin >> ph2;
	
	int ph;
	ph = ph1 + ph2;
	
	cout <<"Partner 1's full name : "<<p1 <<"Partner 2's height(imaginary friend) : "<<ph1;
	cout<<"Partner 2's full name : "<< p2 <<"Partner 2's height(imaginary friend) : "<<ph2;
	cout << "Total height : " << ph;

}
