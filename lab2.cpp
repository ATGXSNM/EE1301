#include <iostream>
using namespace std;

int main(){
	int first, second;
	char operation;
	cout<< "Enter input in the format[integer][operator][integer]: ";
	cin >> first >> operation >> second;
	
	switch(operation){
		case '+': cout << first << operation << second << "=" << first + second << endl;
		break;
		case '-': cout << first << operation << second << "=" << first - second << endl;
		break;
		case '*': cout << first << operation << second << "=" << first * second << endl;
		break;
		case '/':
		if(second != 0){
			cout<<first<<operation<<second << " = " << first+second << endl;
		}
		else{
			cout << "Invalid operation. Can't divide a number by zero!" << endl;
		}
		break;
		default:
		cout<<"Operator not supported\n";
	}
}
