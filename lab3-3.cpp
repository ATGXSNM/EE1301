#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	cout << "\t";
	

		cout << "\n-------------------------------------------------------------\n";
		
		for (int i = 1; i <= 10; i++ ){
			cout << "\t";
			for (int j = 1; j <= 10 ; j++){
				cout << setw(3)<< i*j<< " ";
			}
			cout << endl;
		}
	return 0;
}
