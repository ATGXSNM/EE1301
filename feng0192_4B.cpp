#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream input;
	input.open("statistics.txt");
	
	ofstream output;
	output.open("histogram.txt");
	
	int Grades[5];
	char charTemp;
	
	int numTemp, i = 0;
	int maxGrades = 0;
	
	while(!input.eof()){
		input >> charTemp;
		input >> numTemp;
		Grades[i++] = numTemp;
		
		if(numTemp > maxGrades){
			maxGrades = numTemp;
		}
	}
		
		for(int i = maxGrades; i > 0; i --){
			output << i;
			for(int j =0;j<5;j++){
			if(Grades[j]>= i){
				output<<"X";
			}
			else{
				output<<" ";
				output<<endl;
			}
		}
	}
	output<< "-----" << endl << "ABCDF"<<endl;
	output.close();
}
