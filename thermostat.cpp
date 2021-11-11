#include <iostream>
#include <string>
using namespace std;

int main()
{
  string mode;
  int current_temp, desired_temp;
  bool furnace_on, ac_on;

  cout << "HEAT or COOL? ";
  cin >> mode;

  cout << "Current temperature? ";
  cin >> current_temp;

  cout << "Desired temperature? ";
  cin >> desired_temp;

  if(mode == "HEAT"){
    if(current_temp < desired_temp){
      furnace_on = true;
    }
    else{
      furnace_on = false;
    }
  }else if(mode == "COOL"){ 
    if(current_temp > desired_temp){
      ac_on = true;
    }
    else{
      ac_on = false;
    }
  }else
  {
    furnace_on = false;    
    ac_on = false;    
  }

  if(furnace_on){
    cout << "The furnace is ON" << endl;
  } else if(ac_on){
    cout << "The AC is ON" << endl;
  } else{
    cout << "The furnace and AC are both OFF" << endl;
  }
		
  return 0;
}
