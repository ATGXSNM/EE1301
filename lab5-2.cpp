#include<iostream>
#include<iomanip>

using namespace std;


void minutesToTime(int minute_value,int& hours,int& mins)
{

   mins=minute_value%60;
   hours=minute_value/60;
   
}
int main()
{
   char choice;
   int hours;
   int mins;
   int minute_value;
   while(1)
   {  
       cout<<"Enter number of minutes : ";
       cin>>minute_value;
       minutesToTime(minute_value,hours,mins);

       cout<<"Hours:minutes is "<<hours<<":"<<setfill('0') << setw(2)<<mins<<endl;
       cout<<"Continue? (y/n) : ";
       cin>>choice;

       if(choice=='y')
           continue;
       else
           break;
   }  
   return 0;
}
