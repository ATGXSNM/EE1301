#include <iostream>
using namespace std;

double max(double a, double b)
{
  if(a > b){
    return a;
  }
  else {
    return b;
  }
}

int main()
{
  double x[] = {1.5, 8, 3.1415};
  
  cout << "Max of " << x[0] << " and " << x[1] << " is " << max(x[0], x[1]) << endl;
  cout << "Max of " << x[1] << " and " << x[2] << " is " << max(x[1], x[2]) << endl;
}

