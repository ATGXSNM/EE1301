#include <iostream>
#include <cstdlib>

using namespace std;

class Dice {
	
	private:
	int min;
	int max;
	public:
	Dice();
	Dice(int min, int max);
	void roll(int r);
	void set(int mi, int ma);
	
};

Dice::Dice(){
	
	min=0;
	max=0;
	
}

Dice::Dice(int min, int max){
	Dice::min=min;
	Dice::max=max;
}

void Dice::roll (int r){
	
	float total=0;	
	int cmin=max; 
	int cmax=min;
	int ran=rand() % (max-min+1)+min;
	int t[r];
	
	for(int i=0;i<r;i++){
		
		t[i]=rand() % (max-min+1)+min;
		
		if (t[i]<cmin){
			
			cmin=t[i];
			
		}
		
		if (t[i]>cmax){
			cmax=t[i];
			
		}
		
		total+=(t[i]);
		
	}
	
	cout << "Sample roll : " << ran <<endl;
	cout << "Minimum roll : " << cmin <<endl;
	cout << "Maximum roll : " << cmax <<endl;
	cout << "Average roll : " << total <<endl;	
	
}

void Dice::set (int mi, int ma){
	
	Dice::min=mi;
	Dice::max=ma;
	
}

int* startEndPairs(string s);

int main(){
	int r;
	int min=0, max=0;
	srand(time(0)); 
	cout << "What do you want to roll?  ";
	string s;
	getline(cin, s);
	int* pairs = startEndPairs(s); 
	for(int i=1; i < pairs[0]; i+=2){
		min+=pairs[i];
		max+=pairs[i+1];
	}
	cout << "How many rounds do you want to roll?  ";
	cin >> r;
	Dice* D;
	D=new Dice[r];
	D->set(min,max);
	D->roll(r);	
	delete D;
	delete pairs;	
	return 0;	
}


int* startEndPairs(string s){
	int parts = 0;
	for(int i=0; i < static_cast<signed>(s.length()); i++){
		if(s[i] == 'd' || s[i] == '+'){
			parts++;
		}
	}

	string* data = new string[2*parts];
	
	int index=0;
	unsigned d = s.find('d');
	unsigned p = s.find('+');
	
	while(d != static_cast<unsigned>(-1) || p != static_cast<unsigned>(-1)){
		
		bool dFirst = d < p;
		
		if(dFirst){
			
			string before = s.substr(0,d); 
			int count = 0;
			bool foundDigit=false;
						
			for(int i=0; i< static_cast<signed>(s.length()-d-1); i++){
				if(isdigit(s[count+d+1])){
					
					foundDigit=true;
					
				}
				if(!isdigit(s[count+d+1]) && foundDigit){
					
					break;
					
				}
				
				count++;
				
			}
			
			string after = s.substr(d+1,count); 
			
			data[index] = before;
			data[index+1] = after;
			index+=2;
			
			s = s.substr(d+count+1);
			
		}else {
			
			int count = 0;					
			bool foundDigit=false;
			
			for(int i=0; i< static_cast<signed>(s.length()-p-1); i++){
				
				if(isdigit(s[count+p+1])){
					
					foundDigit=true;
					
				}
				if(!isdigit(s[count+p+1]) && foundDigit){
					
					break;
					
				}
				
				count++;
				
			}
			
			string after = s.substr(p+1,count); 

			data[index] = "+";
			data[index+1] = after;
			index+=2;
			
			
			s = s.substr(p+count+1); 
		}
	
	d = s.find('d');
	p = s.find('+');

	}

	int diceCount = 0;
	for(int i=0; i < parts*2; i+=2){
		if(data[i][0] == '+'){
			diceCount++;
		}else{
			diceCount+=atoi(data[i].c_str());
		}
	}
	
	int* dice = new int[diceCount*2+1]; 
	dice[0] = diceCount*2+1; 
	int ind=1;
	for(int i=0; i < parts*2; i+=2){
		if(data[i][0] == '+'){
			dice[ind] = atoi(data[i+1].c_str());
			dice[ind+1] = atoi(data[i+1].c_str());
			
			ind+=2;
		}else{
			for(int j=0; j < atoi(data[i].c_str()); j++){
				dice[ind] = 1;
				dice[ind+1] = atoi(data[i+1].c_str());
				
				ind += 2;
			}
		}
	}
	
	return dice;
} 
