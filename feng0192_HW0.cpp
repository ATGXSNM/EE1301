//EE1301
//HW0
//ZHIMING FENG
//feng0192
//27.0577
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double inAngle, firstRI, secondRI;
	cout << "Input incident angle: ";
	cin >> inAngle;
	cout << "Input index of refraction of first medium: ";
	cin >> firstRI;
	cout << "Input index of refraction of second medium: ";
	cin >> secondRI;
	
	inAngle = inAngle *M_PI / 180.0; // convert to radians
	double outAngle = 180/M_PI * asin(firstRI/secondRI * sin(inAngle)); //snell's law
	cout << "Refracted angle: " << outAngle <<endl;
	
	return 0;
}
