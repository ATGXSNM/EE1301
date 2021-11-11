#include <iostream>
using namespace std;

int main()
{
   int d,m,y;
   
   cout<<"Enter a date in mm/dd/yyyy format: ";
   cin >> m;
    if (cin.get() != '/' )
    {
       cout << "expected /\n";
       return 1;
    }
    cin >> d; 
    if (cin.get() != '/' ) 
    {
       cout << "expected /\n";
       return 1;
    }
    cin >> y; 
   
   cout<<"Year, month, day: "<<y<<", "<<m<<", "<<d<<endl;
   return 0;
}
