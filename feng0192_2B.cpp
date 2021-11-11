#include <iostream>

using namespace std;

int main(){
	int h, m;
	char c, change_d;
	int h_change, m_change, tot_mins;
	
	cout << "Enter current time (A for AM, P for PM): ";
	cin >> h >> m >> c;
	
	cout << "How many hours forwards or backwards do you want to move the clock(F for forwards, B for backwards) :" ;
	cin >> change_d >> h_change>>m_change;
	
	tot_mins = h * 60 + m;
	
	if(c == 'F'){
		tot_mins += h * 60 + m;
	}
	if(change_d == 'F'){
		tot_mins += h_change * 60 + m_change;
	}
	else{
		tot_mins -= (h_change % 24) * 60 + m_change;
		if(tot_mins<0){
			tot_mins = 1440 - tot_mins;
		}
	}
	string mer = (( tot_mins / 60) / 12) % 2 == 0?"AM":"PM";
	cout << "The new time is : " << ((tot_mins/60)%12) << ":" << (tot_mins%60) << " " << mer << endl;
	return 0;
}
