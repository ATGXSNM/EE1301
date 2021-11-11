#include <iostream>

using namespace std;

int main(){
	
	double h, s,p,t1,t2,t3, s1;
	cout << "Enter the hour that working every week: "<<endl;
	cin >> h;
	cout << "Enter the people that in your house: " << endl;
	cin >> p;
		
	if ( h <= 40 && p < 3){
		s = h * 16.78;
		s1 = (h * 16.78) * 0.75 -10;
		t1 = (h * 16.78) * 0.06;
		t2 = (h * 16.78) * 0.14;
		t3 = (h * 16.78) * 0.05;
		cout << "total pay: " << s<< endl;
		cout << "Social Security tax: " << t1<< endl;
		cout << "Frederal income tax: " << t2<< endl;
		cout << "state income tax: " << t3<< endl;
		cout << "take-home pay: " << s1<< endl;
	}
	else if ( h <= 40 && p >= 3){
		s = h * 16.78;
		s1 = (h * 16.78) * 0.75 -10;
		t1 = (h * 16.78) * 0.06 + 35;
		t2 = (h * 16.78) * 0.14;
		t3 = (h * 16.78) * 0.05;
		cout << "total pay: " << s<< endl;
		cout << "Social Security tax: " << t1<< endl;
		cout << "Frederal income tax: " << t2<< endl;
		cout << "state income tax: " << t3<< endl;
		cout << "take-home pay: " << s1<< endl;
	}
	else if( h > 40 && p < 3 ){
		s = 40 * 16.78 +((h-40) * (16.78*1.5));
		s1 = ((40 * 16.78) +((h-40) * (16.78*1.5)))* 0.75 -10;
		t1 = (40 * 16.78 +((h-40) * (16.78*1.5))) * 0.06;
		t2 = (40 * 16.78 +((h-40) * (16.78*1.5))) * 0.14;
		t3 = (40 * 16.78 +((h-40) * (16.78*1.5))) * 0.05;
		cout << "total pay: " << s<< endl;
		cout << "Social Security tax: " << t1<< endl;
		cout << "Frederal income tax: " << t2<< endl;
		cout << "state income tax: " << t3<< endl;
		cout << "take-home pay: " << s1<< endl;
	}
	else if(h> 40 && p >= 3){
		s = 40 * 16.78 +((h-40) * (16.78*1.5));
		s1 = ((40 * 16.78) +((h-40) * (16.78*1.5)))* 0.75 -10;
		t1 = ((40 * 16.78) +((h-40) * (16.78*1.5))) * 0.06 + 35;
		t2 = (40 * 16.78 +((h-40) * (16.78*1.5))) * 0.14;
		t3 = (40 * 16.78 +((h-40) * (16.78*1.5))) * 0.05;
		cout << "total pay: " << s<< endl;
		cout << "Social Security tax: " << t1<< endl;
		cout << "Frederal income tax: " << t2<< endl;
		cout << "state income tax: " << t3<< endl;
		cout << "take-home pay: " << s1<< endl;
	}
	else{
		cout << "Invalid operation." << endl;
	}
	return 0;
}
