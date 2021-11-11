#include <iostream>

using namespace std;

int last_day(int month, int year){
	int lastday;
	
	if(month < 0 || month > 12){
		return 0;
	}
	else if(month == 4|| month ==6||month ==9|| month ==11){
		lastday = 30;
	}
	else if(month == 2){
		bool leapyear = (year % 4 == 0 && year % 100 != 0)|| (year % 400 == 0);
		
		if(leapyear == 0){
			lastday = 28;
		}
		else{
			lastday = 29;
		}
	}
		else{
			lastday = 31;
			
			
		}
		return lastday;
	}
	
	int main(){
		int month, year;
		char Continue = 'y';
		do{
			cout<<"\n Enter month and year:";
			cin>>month>>year;
			cout<<"\ndays in month:" <<last_day(month, year);
			cout<<"\ncontinue?(y/n)";
			cin >>Continue;
			if(Continue !='y')
			break;}
			while(Continue == 'y');
			return 0;
		}
		
		
