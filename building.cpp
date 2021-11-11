#include <iostream>
#include <string>

using namespace std;

int const SIZE = 100;

// data structure to store nameplate information
struct namePlate
{
  int roomNumber;
  string braille;
  string description;
};

//a class to store info about all the rooms on a floor of the building
class floor
{
private:
  int floor;
public:
  namePlate plates[SIZE];  // an aray of structs
  void setFloor(int i);    // set the floor number of this floor
  void printRoom(int i);   // print the sstatistics for a room
};

void floor::setFloor(int i)
{
  // this member function has direct access to private variables
  floor = i;
}
void floor::printRoom(int i)
{
  cout << floor << "-" << plates[i].roomNumber << endl;
  cout << plates[i].braille << endl;
  cout << plates[i].description << endl << endl;
}


int main()
{
  floor keller[6];  // 6 floors in keller hall

  keller[0].setFloor(1);
  keller[0].plates[0].roomNumber=200;
  keller[0].plates[0].description="EE1301 Lab";
  keller[0].plates[0].braille=".: . .. : .: .:";
  
  keller[0].plates[1].roomNumber=240;
  keller[0].plates[1].description="Another Lab";
  keller[0].plates[1].braille=":..:";
  
  keller[3].setFloor(4);
  keller[3].plates[0].roomNumber = 163;
  keller[3].plates[0].braille = ".: .: .. . :. ..";
  keller[3].plates[0].description = "Prof. John Sartori\nECE Department\n612-625-0811";
	
  keller[3].plates[1].roomNumber = 174;
  keller[3].plates[1].braille = ".: .: .. . :: .:";
  keller[3].plates[1].description = "ECE Department\nMain Office";
  
  // print the stored info
  for(int fnum=0; fnum<6; fnum+=3){
    for(int pnum=0; pnum<=1; pnum++){    
      keller[fnum].printRoom(pnum);
    }
  }
  
  return 0;
}
















/*
#include <iostream>

using namespace std;

const int SIZE = 100;

struct room
{
	string description;
	string number;
	int capacity;
};

class floor
{
public:
	room rooms[SIZE];
	string floorLabel;
	void printRoom(int i);
};


int main()
{
	room groundRooms[SIZE] = {{"General Classroom", "210", 250},
	{"General Classroom", "230", 109}};
	
	
	floor one;
	one.rooms[0] = groundRooms[0];
	one.rooms[1] = groundRooms[1];
	one.floorLabel = "1";
	
	//room upOneRooms[SIZE] = {"Main office", "192", 5};
	floor two = {{"Main office", "192", 5}, "2"};
	
	one.printRoom(0);
	
	// and so on... (could use an array)
}

void floor::printRoom(int i)
{
	cout << floorLabel << "-" << rooms[i].number;
}
*/
