#include <iostream>
#include <time.h>

using namespace std;

int main(){
	srand(time(NULL));
	
	int random = (rand()%9)+1;
	int count = 0;
	int in;
	
	while(count != 3){
		
		cout << "What is the random number I guessed?:";
		cin >> in;
		
		if(random - in == 1 || random - in == -1){
			cout << "Close!";
		}
		else if(in < random){
			cout << "Too low!";
		}
		else if(in > random){
			cout << "Too high!";
		}
		else{
			cout<<"Correct!";
			cout<<"\n\n";
			return 0;
		}
		cout << "\n";
		count ++;
	}
	cout << "You lose, the number was "<< random << "!";
	cout <<"\n\n";
	return 0;
}
