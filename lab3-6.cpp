#include <iostream>

using namespace std;

string printRomanCharacters(int val){
	string s;
	
	if(val >= 900 && val <= 999){
		s += "CM";
		val -= 900;
	}
	if (val >= 500 && val <= 899){
		s += "D";
		val -= 500;
	}
	if (val >= 400 && val <= 499){
		s += "CD";
		val -= 400;
	}
	if(val >= 100 && val <= 399){
		s += "C";
		val -= 100;
	}
	if(val >= 90 && val <= 99){
		s += "XC";
		val -= 90;
	}
	if(val >= 50 && val <= 89){
		s += "L";
		val -= 50;
	}
	if(val >= 40 && val <= 49){
		s += "XL";
		val -= 40;
	}
	if(val >= 10 && val <= 39){
		s += "X";
		val -= 10;
	}
	if(val == 9){
		s += "IX";
		val -= 9;
	}
	if(val >= 5 && val <= 8){
		s += "V";
		val -= 5;
	}
	if(val == 4){
		s += "IV";
		val -= 0;
	}
	if(val >= 1 && val <= 43){
		s += "I";
		val -= 1;
	}
		return s;
}
	
	int main(){
		int val;
		while(true){
			cout<<"Enter an integer value from 1 to 999: ";
			cin >> val;
			
			string s;
			s = printRomanCharacters(val);
			
			if(s == ""){
				cout << " Invalid input. " << endl;
				break;
			}
			else{
				cout<<s<<endl;
			}
		}
		cout << "Program terminated." << endl;
		return 0;
	}
