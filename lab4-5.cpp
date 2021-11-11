#include <iostream>

using namespace std;

double myPow(double k, int n) {
    if(n == 1) {
        return k;
    }
    return k * myPow(k, n-1);
}

double rootN(double k, int n) {

    double xStart = 1; 

    double eps = 1e-4; 

    double delX; 

    double xCurrent; 

    do
    {
        xCurrent = ((n - 1.0) * xStart + 
              (double)k/myPow(xStart, n-1)) / (double)n; 
        delX = xCurrent - xStart; 
    delX = (delX > 0) ? delX : -delX;
        xStart = xCurrent; 
    } while (delX > eps);

    return xCurrent; 
}

int main() {
    char choice = 'y';

    while(choice == 'y') {
        double k, n;
        cout << "Enter value and root: ";
        cin >> k >> n;
        cout << "The root is: " << rootN(k, n) << endl;
        cout << "continue? ";
        cin >> choice;
        cout << endl;
    }
}
