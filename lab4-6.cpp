#include <iostream>
#include <cmath>

using namespace std;

int GCD(int a, int b);

int main() {
   while(true) {
       int a, b;
      
       cout << "enter two integer values: ";
       cin >> a >> b;
      
       cout << "greatest common divsor is: " << GCD(a,b) << endl;
      
       char userInput;
       cout << "continue? (y/n): ";
       cin >> userInput;
      
       if('y' != userInput) {
           break;
       }
   }
   return 0;
}


int GCD(int a, int b) {
   a = abs(a);
   b = abs(b);
   while(true) {
       int r = a % b;
       if(0 == r) break;
       a = b;
       b = r;
   }
   return b;
}
