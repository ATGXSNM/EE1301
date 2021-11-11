#include<iostream>
using namespace std;

void tmrw(int,int,int);

int main(){

int d,m,y;

char ch='y';

while ((ch!='N') && (ch!='n')){
   
cout<<"enter date as mm dd yyyy"<<endl;
cin>>m>>d>>y;
tmrw(d,m,y);
cout<<"continue (y/n)" << endl;
cin>>ch;
}

}

void tmrw (int d,int m,int y){
	if((d>31)||(m>12)){
		cout<<"invalid date";
		}
		else if ((m==12)&&(d==31)){
			y++;
			d = 1;
			m = 1;
			}
			else if ((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12)){ 
				if(d<31){
				d++;
			}
				else{
					d=1; m++;
					}
					}
					else if(m==2){
						bool ly = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
						if(ly == 0 && d < 28){
							d ++;
							}
							else if(ly == 0 && d == 28){
								d = 1;
								m++;
								}
								else if(ly != 0 && d <29){
									d ++;
								}
								else if(ly != 0 && d == 29){
									d=1;
									m++;
									}
									else{
										cout<<"invalid date";
										}
									}
									else{
										if(d<30){
											d++;
											}
										else if(d==30){
											d=1;m++;
											}
										else{
										cout<<"invalid date";
										}
									}
									
											cout<<"next day is:"<<m<<" "<<d<<" "<<y;
										}
