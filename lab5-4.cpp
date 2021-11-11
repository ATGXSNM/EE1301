#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main () {
ofstream myfile; 
string fname,stime,atime;
myfile.open("flightData.dat"); 
if (!myfile.is_open()) { 
cout<< "unable to open file\n";
exit(0);
}
myfile<< "FlightNumber ScheduledArrivalTime ActualArrivalTime\n";
while(true){
cout << "Enter the flight Number:";
cin >> fname;
if(fname.compare("end")==0)
break;
cout << "Enter the sheduled/actual arrival times:";
cin >> stime;
cin >> atime;
myfile << fname << " " << stime << " " << atime << endl; 
}
myfile.close(); 
return 0;
}
