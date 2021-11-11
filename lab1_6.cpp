
#include <iostream>
#include <string>
using namespace std;

int main(){
	string first, middle, last;
	cout << "Enter your name :";
	cin >> first >> middle>> last;
	if(last.compare("m")==1){
		cout<<middle<<" "<<first<<" "<<endl;
	}
	else
	cout <<last << " " <<first << " " << middle <<endl;
	
		return 0;


}
