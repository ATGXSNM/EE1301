#include <iostream>
#include <iomanip>
using namespace std;

class Complex
{

   double real;
   double imag;

   public:

   Complex()
   
   {

       real = imag = 0;
   }

  
   void input(istream &cin)
   {
       cin>>real;
       cin>>imag;
   }
  
   void output(ostream &cout)
   {
       cout<<fixed<<setprecision(1)<<real<<" + "<<fixed<<setprecision(1)<<imag<<"i"<<endl;
   }
  
   double getReal()
   {
       return real;
   }
  
   double getImag()
   {
       return imag;
   }
  
   void setReal(double inReal)
   {
       real = inReal;
   }
  
   void setImag(double inImag)
   {
       imag = inImag;
   }
};

int main()
{

   Complex c1, c2;
  
   cout<<"Enter values for real and imaginary coefficients: ";
   c1.input(cin);
   
   cout<<"Enter values for real and imaginary coefficients: ";
   c2.input(cin);
  
   c1.output(cout);
   c2.output(cout);
   double newReal;
   cout<<"Enter a new value for the real coefficient: ";
   cin>>newReal;

   c2.setReal(newReal);
  
   cout<<"The new real coefficient is "<<fixed<<setprecision(2)<<c2.getReal()<<endl;
  
   c2.output(cout);
  
  
   return 0;
} 
