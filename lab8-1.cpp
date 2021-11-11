#include <iostream>
using namespace std;

class Timer{
	public:
	int hr;
	int minute;
	Timer(int h,int min){
		h=h+min/60;
		min=min%60;
		hr=h;
		minute=min;
	}
};
		
		int main(){
			Timer *t=new Timer(10,20);
			cout<<"Time : "<<t->hr<<" hour :"<<t->minute<<" minute"<<endl;
			return 0;
		} 
