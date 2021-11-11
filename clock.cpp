#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  
  int hours,mins, hours_m, mins_m;
  char garbage, ampm, f_or_b;

  cout << "Enter current time (A for AM, P for PM): ";
  cin >> hours  >> mins >> ampm;

  cout << "How many hours forwards or backwards do you want to move the clock (F for forwards, B for backwards): ";
  cin >> f_or_b >> hours_m >> mins_m; 

  if(ampm == 'P' && hours > 12){
    hours += 12;
  }
  if(f_or_b == 'F'){
    hours += hours_m;
    mins += mins_m;
    hours += (mins/60);
    mins %= 60;
    hours %= 24;
    if(hours > 12){
      hours -= 12;
      ampm = 'P';
    } else if(hours == 12){
      ampm = 'P';
    } else if(hours == 0){
      hours = 12;
      ampm = 'A';
    }else{
      ampm = 'A';
    }
  }

  cout << "The new time is: " << hours << ":" << setw(2) << setfill('0') << mins;
  if(ampm == 'A'){
    cout << " AM\n";
  } else{
    cout << " PM\n";
  }
  
  return 0;
}
