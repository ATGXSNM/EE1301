#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

inline int timeToMinutes(string time);
string MinutesToTime(int minutes);
int elapsedTime(int sch_time, int arrival_time);

int main()
{

   string flight_name[20],
       scheduled_time[20],
       arrival_times[20];

   int delay_time[20];

   int sum_delay = 0, avg_delay = 0,max,min,
       i = 0, j = 0, k = 0,m,ctr = 0;;

   ifstream myfile;
   string filename, max_flight, min_flight;


   cout << "Enter the filename to read: ";
   cin >> filename;

   myfile.open(filename.c_str());

   if (!myfile.is_open())
   {

       cout << "Unable to open file\n";
       exit(0);
   }

   while (!myfile.eof())
   {


       myfile >> flight_name[ctr];
       myfile >> scheduled_time[ctr];
       myfile >> arrival_times[ctr];

       i= timeToMinutes(scheduled_time[ctr]);

       j= timeToMinutes(arrival_times[ctr]);

       delay_time[k] = elapsedTime(i,j);

       sum_delay += delay_time[k];

       k++;
   }  

   avg_delay = sum_delay / k;

   max = delay_time[0];
   min = delay_time[0];

   for (m = 0; m < k; m++)
   {  
       if (max < delay_time[m])
       {
           max = delay_time[m];
           max_flight = flight_name[m+1];
       }          
       if (min > delay_time[m])
       {
           min = delay_time[m];          
           min_flight = flight_name[m+1];
       }
   }

   cout << "Time delay: " << MinutesToTime(avg_delay) << endl;

   cout << "Maximum flight delay number is " << max_flight
       << " with the "<< MinutesToTime(max)<<" delay" << endl;

   cout << "Minimum flight delay number is " << min_flight
       << " with the "<< MinutesToTime(min)<< " delay"<< endl;
   return 0;
}


int timeToMinutes(string time)
{

   int total_minutes = 0;

   int idx = time.find(':');

   int hrs = strtol(time.substr(0, idx).c_str(), NULL, 10);
   int mins = strtol(time.substr(idx + 1).c_str(), NULL, 10);

   total_minutes = hrs * 60 + mins;

   return total_minutes;
}


string MinutesToTime(int minutes)
{

   char buf[66];

   sprintf(buf, "%d:%d", minutes / 60, minutes % 60);

   return string(buf);
}


int elapsedTime(int sch_time,int arrival_time)
{


   int elapsedTime = arrival_time - sch_time;

   return elapsedTime;
}
