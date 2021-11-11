#include <iostream>

using namespace std;

int printRomanCharacters(  int val){
	if(val >= 900 && val <= 999){
		cout << "CM";
		return val -900;
	}
	else if (val >= 500 && val <= 899){
		cout << "D";
		return val -500;
	}
	else if (val >= 400 && val <= 499){
		cout << "CD";
		return val - 400;
	}
	else if(val >= 100 && val <= 399){
		cout << "C";
		return val - 100;
	}
	else if(val >= 90 && val <= 99){
		cout << "XC";
		return val - 90;
	}
	else if(val >= 50 && val <= 89){
		cout << "L";
		return val - 50;
	}
	else if(val >= 40 && val <= 49){
		cout << "XL";
		return val - 40;
	}
	else if(val >= 10 && val <= 39){
		cout << "X";
		return val - 10;
	}
	else if(val == 9){
		cout << "IX";
		return 0;
	}
	else if(val >= 5 && val <= 8){
		cout << "V";
		return val - 5;
	}
	else if(val == 4){
		cout << "IV";
		return 0;
	}
	else if(val >= 1 && val <= 43){
		cout << "I";
		return val - 1;
	}
	else{
		return 0;
	}
}
	
	int main(){
		int num;
		while(true){
			cout<<"Enter an integer value from 1 to 999: ";
			cin >> num;
			
			if(num <= 0 || num > 999){
				cout << " Invalid input. " << endl;
				break;
			}
			else{
				while(num = printRomanCharacters(num));
				cout << endl;
			}
		}
		cout << "Program terminated." << endl;
		return 0;
	}
