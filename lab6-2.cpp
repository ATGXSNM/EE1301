#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();
void printArray(string fullName[], double height[], int size);

int main(){
	int size= requestNumberOfPartners();
	string fullName[size];
	double height[size];
	
	for(int i = 0; i < size; i++){
		fullName[i] = requestName();
		height[i] = requestHeight(fullName[i]);
		}
		printArray(fullName, height, size);
}
string requestName(){
	string name;
	cout << "Please enter full name: ";
	cin >> name;
	return name;
	}
double requestHeight(string fullName){
	double height;
	cout << "Please enter " << fullName << "'s height: ";
	cin >> height;
	return height;
	}
	
int requestNumberOfPartners(){
	int numberOfPartners;
	cout << "How many partners are there? ";
	cin >> numberOfPartners;
	return numberOfPartners;
	}
void printArray(string fullName[], double height[], int size){
	double sum = 0;
	for (int i = 0; i < size; ++i){
		sum = sum + height[i];
}

for (int i = 0; i < size-1; ++i)
{
cout << fullName[i] << " and ";
}
cout << fullName[size-1];

cout << " stand on top of each other, their combined height will be " << sum << endl;
}
