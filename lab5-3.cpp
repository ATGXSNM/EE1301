#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void elapsedTime(int h1,int m1,int h2,int m2,int& h,int& m);

int main()
{
   int h1, m1, h2, m2;
   int h=0,m=0;
   string time1,time2;
   bool repeat=true;
  
   do
   {
   	
       cout<<"\nEnter first time (hours:minutes) : ";
       cin>>time1;
      
       cout<<"\nEnter second time (hours:minutes) : ";
       cin>>time2;
      
      
       int colon1idx,colon2idx;
      
       colon1idx=time1.find(":");
       colon2idx=time2.find(":");
      
       string h1str, m1str, h2str, m2str;
       char ch;
      
       h1str=time1.substr(0,colon1idx);
       m1str=time1.substr(colon1idx+1);
      
       h2str=time2.substr(0,colon2idx);
       m2str=time2.substr(colon2idx+1);
      
       stringstream conv(h1str);
       conv>>h1;
      
       stringstream conv1(m1str);
       conv1>>m1;
      
       stringstream conv2(h2str);
       conv2>>h2;
      
       stringstream conv3(m2str);
       conv3>>m2;
      
       elapsedTime(h1,m1,h2,m2,h,m);
      
       if(m==0)
       {
           cout<<"\nElapsed time is: "<<h<<":"<<m<<"0\n";
       }
       else if(m<10)
       {
           cout<<"\nElapsed time is: "<<h<<":"<<"0"<<m<<"\n";
       }
       else
       {
           cout<<"\nElapsed time is: "<<h<<":"<<m<<"\n""";
       }
      
       cout<<"\nContine? (y/n): ";
       cin>>ch;
      
       if(ch=='y' || ch=='Y')
       {
           repeat=true;
       }
       else
       {
           repeat=false;
       }
   }while(repeat);
  
   return 0;
}

void elapsedTime(int h1,int m1,int h2,int m2,int &h,int &m)
{

   if(h1>h2)
       h=(h1-h2);
   else
       h=(h2-h1);
      
   if(m1>m2)
       m=(m1-m2);
   else
       m=(m2-m1);
}
