#include <iostream>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();


int main(){
    string fullName[2];
    double height[2];

    for(int i = 0; i < 2; i++){
        fullName[i] = requestName();
        height[i] = requestHeight(fullName[i]);
    }
    	cout << "If " << fullName[0] << " and " << fullName[1]
	     << " form a human tower, their combined height will be "
	     << (height[0] + height[1]) << endl;
	     return 0;
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
    cout << "How many partners are there?";
    cin >> numberOfPartners;

    return numberOfPartners;
}


