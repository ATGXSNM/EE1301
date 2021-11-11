#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main () {
ofstream myfile; // output stream
string fname,stime,atime;
myfile.open("flightData.dat"); // open file
if (!myfile.is_open()) { // check if file is open or not
cout<< "unable to open file\n";
exit(0);
}
myfile<< "FlightNumber ScheduledArrivalTime ActualArrivalTime\n";
while(true){
cout << "Enter the flight Number:";
cin >> fname;
if(fname.compare("end")==0) // check if input is end
break;
cout << "Enter the sheduled/actual arrival times:";
cin >> stime;
cin >> atime;
myfile << fname << " " << stime << " " << atime << endl; // write to file
}
myfile.close(); // close file
return 0;

}
