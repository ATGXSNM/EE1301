#include <iostream>

using namespace std;

int minutesToTime(int hours,int mins){
	
	int value;
	
	value += hours *60;
	value += mins;
	
	return value;
	
}

int main(){
	char choice;
	int hours;
	int mins;
	int value;
	while(1){
		
		cout<< "Enter a time duration(hh:mm):";
		cin >> hours;
		
		if (cin.get() != ':'){
			
			cout <<  "Wrong information.";
			return 1;
			
		}
		cin >> mins;
		
		//minutesToTime(hours, mins);
		
		cout<< "Total minutes: " << minutesToTime(hours, mins)<<endl;
		
		cout<<"Continue? (y/n) : ";
       cin>>choice;
       
       if(choice == 'y')
       continue;
       else
       break;
       
	}
	return 0;
}
