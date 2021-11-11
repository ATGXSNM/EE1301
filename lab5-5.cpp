
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{

string data, flightNum, stime, atime;
int hoursTime1, hoursTime2, minuteTimes1, minuteTimes2;
char flightData[100];
char *delayTime = NULL;

string fileData = "flightData.dat";

ofstream myfile;


try
{
  myfile.open(fileData);
}

catch (exception &ex)
{
  cout << "Unable to open file"
   << ex.what() << "!\n";
  return 0;
}
do
{

  cout << "\nEnter the flight number: ";
  cin >> flightNum;

  if (flightNum != "end")
  {
   myfile << flightNum << " ";
   cout << "Enter the scheduled arrival time(HH:MM): ";
   cin >> stime;
   myfile << stime << " ";
   cout << "Enter the actual arrival time(HH:MM): ";
   cin >> atime;
   myfile << atime << "\n";
  }
} while (flightNum != "end");

myfile.close();

ifstream inFile;


try
{
  inFile.open(fileData);
}

catch (exception &ex)
{
  cout << "Unable to open file"
   << ex.what() << "!\n";
  return 0;
}

while (getline(inFile, data))
{

  strcpy_s(flightData, data.c_str());

  flightNum = strtok_s(flightData, " ", &delayTime);

  hoursTime1 = stoi(strtok_s(NULL, ":", &delayTime));

  minuteTimes1 = stoi(strtok_s(NULL, " ", &delayTime));
  hoursTime2 = stoi(strtok_s(NULL, ":", &delayTime));
  minuteTimes2 = stoi(strtok_s(NULL, " ", &delayTime));
  int delayHH, delayMM;

  if (minuteTimes2 < minuteTimes1)
  {
   delayMM = (minuteTimes2 + 60) - minuteTimes1;
   hoursTime2 -= 1;
   delayHH = hoursTime2 - hoursTime1;
  }

  else
  {
   delayHH = hoursTime2 - hoursTime1;
   delayMM = minuteTimes2 - minuteTimes1;
  }
  cout << "Flight:" << flightNum << endl;
  cout << "Delay Time: " << delayHH << ":" << delayMM << "\n" << endl;
}
inFile.close();
return 0;
}
