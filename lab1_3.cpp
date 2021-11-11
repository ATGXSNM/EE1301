#include <iostream>
#include <string>
using namespace std;

int main(){
	string a,b,c;
	string A,B,C;
	A = "YES";
	B = "NO";
	C = " NO";
	
	
	cout <<"q1";
	cin >> a;
	if (A == a){
		cout <<"Great";
		cout <<"q2";
		cin >>b;
		if( B == b){
			cout << "GREAT";
			cout << "q3";
			cin >> c;
			if (C == c){
				cout <<"GREAT";
			}
			else{
				cout << "get out";
			}
		}else{
				cout << "get out";
			}
		}
			else{
				cout <<"get out";
			}
}

