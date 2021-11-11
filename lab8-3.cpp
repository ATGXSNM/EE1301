#include<iostream>
#include <ctime>
#include<string.h>

using namespace std;

double *momentum(double velocity[3], double mass){

     double *arymntm = new double[3];

     for (int i=0; i<3; i++)

     {

          arymntm[i] = velocity[i] * mass;   

     }

     return arymntm;

}


int main(){

     double mass;

     double velocity[3];

	cout<<"Enter the three velocity values from -100.0 through +100.0:";

     for (int i=0; i<3; i++){
          cin>>velocity[i];
	  }

	cout<<"Enter the mass values in the range 1.0 through 10.0:";

    cin>>mass;

    double *res=momentum(velocity,mass);

    cout<<"Momentum values:";

    for (int i=0; i<3; i++){
          cout<<res[i]<<"    ";
	  }


    return 0;

} 


