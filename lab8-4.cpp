#include<iostream>
#include<string.h>
#include <ctime>

using namespace std;

double *momentum(double *velocity, double mass)

{

     double *arymntm = new double[3];

     for (int i=0; i<3; i++)

     {

          arymntm[i] = velocity[i] * mass;   

     }

     return arymntm;

}

double *randVec()

{
	 srand(time(NULL));

     double *velVec = new double[3];

     for (int i=0; i<3; i++)

     {

          velVec[i] = rand() %200+(-100);

     }

     return velVec;

}


int main()

{

	 int it = 0;
     double mass[1000];

     double *velocity[1000];

     double *res[1000],sum[3];
     
     for (int i = 0; i < 3; i++)
		sum[i] = 0;

     for (it=0;it<1000;it++)

     {

          mass[it]=(rand() % 10)+1;

          velocity[it]=randVec();

          res[it]=momentum(velocity[it],mass[it]);

          for(int i=0; i<3; i++)
          
              sum[i]=sum[i]+res[it][i];

     }

	 cout << "Average of Momentum: " << sum[0]/it << "i + " << sum[1]/it << "j + " << sum[2]/it << "k" << endl;
     return 0;

} 
