#include <iostream>
using namespace std;

#ifndef BUG_H
#define BUG_H

class Bug
{
    public:
       
        int position;
        int direction = 1;
       
        Bug();
        Bug(int initialPosition);

        void move();

        void turn();
       
        void display();
};
#endif

Bug::Bug(){
	position = 0;
	direction = 1;
}

Bug::Bug(int initialPosition)
{

    position = initialPosition;
   
}

void Bug::move()
{
	if(direction == 1){
    position++;
}
else{
	position --;
}
   
}


void Bug::turn()
{
    if (direction == 1)
    {
        direction = direction - 2;
    }
   
    else
    {
        direction = 1;
    }       
}


void Bug::display()
{
	cout << "Position: " << position << ", Direction: " << direction << endl;  
}

