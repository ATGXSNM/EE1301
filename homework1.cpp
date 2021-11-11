
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159;

int main(){
	double radius, height;
	
	cout << "Input the radius of the  sphere: ";
	cin >> radius;
	
	cout << "Input the height of the fluid: ";
	cin >> height;
	
	if ( radius>0 && height >0){
		double volume = 4 * PI * pow(radius, 3)/3;
		double surface_area = 4 * PI * pow(radius, 2);
		double liquid_volume = PI * pow(height, 2) * (3*radius -height)/3.0;
		double fluid_surface_area = 2 * PI *radius * height;
		
		cout << fixed << setprecision(2);
		
		cout << "Volume of the entire tank: "<<volume << endl;
		cout << "Surface area if the entire tank: " << surface_area <<endl;
		cout << "Volume of the fluid: " << liquid_volume << endl;
		cout << "Surface area covered by the fluid : " << fluid_surface_area << endl;
	}
	else{
		cout << "Radius or Height cannot be in negative. \n";
	}
}
