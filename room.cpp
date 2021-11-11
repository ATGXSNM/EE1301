#include <iostream>
#include <string>
using namespace std;


struct namePlate
{
  int floor;
  int roomNumber;
  string braille;
  string description;
};

int main()
{
	namePlate plates[250];
	plates[0].floor = 4;
	plates[0].roomNumber = 163;
	plates[0].braille = ".: .: .. . :. ..";
	plates[0].description = "Prof. John Sartori\nECE Department\n612-625-0811";
	
	plates[1] = {1, 200, ".: . .. : .: .:", "EE1301 Lab"};
	//plates[1].floor = 1;
	//plates[1].roomNumber = 200;
	//plates[1].braille = ".: . .. : .: .:";
	//plates[1].description = "EE1301 Lab";
	
	plates[2].floor = 4;
	plates[2].roomNumber = 174;
	plates[2].braille = ".: .: .. . :: .:";
	plates[2].description = "ECE Department\nMain Office";
	
	for(int i=0; i<3; i++){
	  cout << plates[i].floor << "-" << plates[i].roomNumber << endl;
	  cout << plates[i].braille << endl;
	  cout << plates[i].description << endl << endl;
	}
	
	return 0;
}

















/*

#include <iostream>

using namespace std;

struct room
{
	string description;
	string number;
	int capacity;
};

int main()
{
	room replate[] = {{"General Classroom", "3-210", 250},
	{"General Classroom", "3-230", 109},
	{"Main office", "4-192", 5}};
	
	cout << replate[2].capacity;
	
	// and so on... (could use an array)
}
*/
