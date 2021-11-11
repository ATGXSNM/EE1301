#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const char BLANK = '-';
const char ROBOT = 'X';
const char GOAL = 'O';
const char wall = 'W';
const int length = 10;

bool hasChar(char pos[][length],int length, char findMe);
void clearScreen();
void showGrid(char pos[][length],int length);
int updateGrid(char pos[][length],int length,int & xPos,int &yPos, char action);


int main()
{
	char pos[length][length];

	
	ifstream fin;
	fin.open("grid.txt");
	if (!fin) {
		cout << "Unable to open file";
		exit(1);
		}
		
		for(int i=0; i < length; i++){
			for(int j=0; j < length; j++){
				pos[i][j] = BLANK;
				}
				}
	
	pos[0][0] = GOAL;
	pos[length/2][length/2] = ROBOT;
	
	int xPos = length/2;
	int yPos = length/2;
	
	for(int i=0; i < length; i++){
		for(int j=0; j < length; j++){
			fin>>pos[i][j];
			if(pos[i][j]==ROBOT){
				xPos = j;
				yPos = i;
				}
			}
	}
	
	string msg="";

	while(hasChar(pos, length, GOAL))
	{

		char action;
		clearScreen();
		showGrid(pos, length);
		cout << msg;
		cout << "Where would you like to go? (l, r, u, d) " << endl;
		cin >> action;


		
		int moveMade = updateGrid(pos, length, xPos, yPos, action);
		
		if(moveMade == 0){
			msg = "Yout hit the wall.\n";

		}
		else{
			msg = "";
		}
		
	}
	
	clearScreen();
	showGrid(pos, length);
	cout << "You won!  Have a cookie.\n";
	
	return 0;
}

bool hasChar(char pos[][length],int length, char findMe)
{
	for(int i=0; i < length; i++)
	{
		for(int j=0; j < length; j++)
		{
			if(pos[i][j] == findMe)
			{
				return true;
			}
		}
	}
	
	return false;
}

void clearScreen()
{
	cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void showGrid(char pos[][length],int length)
{
	for(int i=0; i < length; i++)
	{
		for(int j=0; j < length; j++)
		{
			cout << pos[i][j];
		}
		cout << endl;

	}
}

int updateGrid(char pos[][length],int length,int & xPos, int & yPos,char action)
{
	pos[yPos][xPos] = BLANK;
	
	int o_xPos = xPos;
	int o_yPos = yPos;

	if(tolower(action) == 'l' && xPos > 0)
	{
		xPos--;
	}	
	else if(tolower(action) == 'r' && xPos < length - 1)
	{
		xPos++;
	}
	else if(tolower(action) == 'u' && yPos > 0)
	{
		yPos--;
	}	
	else if(tolower(action) == 'd' && yPos < length - 1)
	{
		yPos++;
	}
	
	if(pos[yPos][xPos] == wall){
		xPos = o_xPos;
		yPos = o_yPos;
		pos[yPos][xPos] = ROBOT;
		return 0;
	}
	else if(yPos < 0 || yPos > 10 || xPos < 0 || xPos > 10){
		xPos = o_xPos;
		yPos = o_yPos;
		pos[yPos][xPos] = ROBOT;
		return 0;
	}
	else{
		pos[yPos][xPos] = ROBOT;
		pos[o_yPos][o_xPos] = BLANK;
	}
	
	return 1;
}

