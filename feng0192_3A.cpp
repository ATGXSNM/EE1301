#include <iostream>
#include <time.h>

using namespace std;

string getRPS(int i){
	switch (i){
	
	case 0:
	return "rock";
	break;
	
	case 1:
	return"paper";
	break;
	
	case 2:
	return"scissors";
	break;
}

return"";
}
int rps(int i, int j){
	if(i == j){
		cout<<" Your both tie by playing " << getRPS(j)<<" \n ";
		return 0;
	}
	if(i == 0 && j == 2){
		cout <<" Your "<<getRPS(i)<<" beat the computer's "<<getRPS(j)<<" !\n ";
		return 1;
	}
	if(i==1 && j==0){
		cout <<" Your "<<getRPS(i)<<" beat the computer's "<<getRPS(j)<<" !\n ";
		return 1;
	}
	if(i==2 && j ==1){
		cout <<" Your "<<getRPS(i)<<" beat the computer's "<<getRPS(j)<<" !\n ";
		return 1;
	}
	cout <<" Your "<<getRPS(i)<<" beat the computer's "<<getRPS(j)<<" !\n ";
	return 0;
}

int main(){
	
	srand(time(NULL));
	
	int count = 0;
	cout<<"How many games of Rock-Paper-Scissor do you wish to play?";
	cin >> count;
	char in;
	int win = 0;
	
	while(count != 0){
		cout << "Rock....Paper....Scissors....!";
		cin >> in;
		int random = (rand()%3);
		
		switch(in){
			
			case'R':
			win += rps(0,random);
			break;
			
			case 'P':
			win += rps(1,random);
			break;
			
			case'S':
			win += rps(2,random);
			break;
			
			default:
			cout << "Invalid input, stopping..";
			return 0;
			break;
		}
		count --;
	}
	if(win > count-win){
		cout << "Congratulations, you beat the computer!";
	}
	else if(win < count-win){
		cout <<"You lost to the computer, better luck next time.";
	}
	else{
		cout <<"The game ends in a draw.";
	}
	cout<<"\n\n";
	return 0;
}
