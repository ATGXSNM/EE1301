#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	ifstream input;
	input.open("grades.txt");
	
	ofstream output;
	output.open("statistics.txt");
	
	string firstname, lastname;
	double grade;
	
	int grades[12] = {0};
	int A = 0, B = 0, C = 0, D = 0, F = 0;
	
	while (input >> firstname >> lastname >> grade){
		if(grade >= 93){
			grades[0]++;
			A++;
		}
		else if(grade >= 90){
			grades[1]++;
			A++;
		}
		else if(grade >= 87){
			grades[2]++;
			B++;
		}
		else if(grade >= 83){
			grades[3]++;
			B++;
		}
		else if(grade >= 80){
			grades[4]++;
			B++;
		}
		else if(grade >= 77){
			grades[5]++;
			C++;
		}
		else if(grade >= 73){
			grades[6]++;
			C++;
		}
		else if(grade >= 70){
			grades[7]++;
			C++;
		}
		else if(grade >= 67){
			grades[8]++;
			D++;
		}
		else if(grade >= 63){
			grades[9]++;
			D++;
		}
		else if(grade >= 60){
			grades[10]++;
			D++;
		}
		else{
			grades[11]++;
			F++;
		}
	}
	input.close();
	
	cout<<grades[0]<<" A"<<endl;
	cout<<grades[1]<<" A-"<<endl;
	cout<<grades[2]<<" B+"<<endl;
	cout<<grades[3]<<" B"<<endl;
	cout<<grades[4]<<" B-"<<endl;
	cout<<grades[5]<<" C+"<<endl;
	cout<<grades[6]<<" C"<<endl;
	cout<<grades[7]<<" C-"<<endl;
	cout<<grades[8]<<" D+"<<endl;
	cout<<grades[9]<<" D"<<endl;
	cout<<grades[10]<<" D-"<<endl;
	cout<<grades[11]<<" F"<<endl;
	
	output<<"A "<< A << endl;
	output<<"B "<< B << endl;
	output<<"C "<< C << endl;
	output<<"D "<< D << endl;
	output<<"F "<< F << endl;
	
	output.close();
	return 0;
}
