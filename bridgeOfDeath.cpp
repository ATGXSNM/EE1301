#include <iostream>
#include <string>

using namespace std;

int main()
{
  string name, quest, tricky, temp;
  cout << "STOP!\n";
  cout << "He who would cross the Bridge of Death\n";
  cout << "Must answer me these questions three\n"; 
  cout << "Ere the other side he see.";
  cout << "\n\n";
  cout << "WHAT... is your name?\n";

  getline(cin,name);  // read name from keyboard
  
  if(name.compare("Sir John of Minnesota") == 0)
  {
    cout << "WHAT... is your quest?\n";
    getline(cin,quest); // read quest from keyboard
    
    if(quest == "To seek the holy grail")
    {
      cout << "WHAT... does the fox say?\n";

      getline(cin,tricky);
      if(tricky == "ring ding ding ding dingeringeding")
      {
	cout << "Okay... off ya go!\n";
	return 0;
      }
    }
  }
  
  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHH!!!!!!!\n\n";
  
  return 0;
}

