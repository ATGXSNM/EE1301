#include<iostream>
#include<math.h>

using namespace std;

int encode(int a, int e, int n){

   return (static_cast<int>(pow(static_cast<double>(a),e)) % n);
}

int char_to_number(char a){
    return a - 64;
}

int gcd(int a, int b){

    int res = 1;
    if (a > b ){
       if ( a % b == 0)
          return b;
       for (int i = 2; i<b; i++){
           if ( a % i == 0 && b % i == 0)
              res = i;         
       }
    }
    if (b > a){
       if ( b % a == 0)
          return a;
       for (int i = 2; i<a; i++){
           if ( b % i == 0 && a % i == 0)
              res = i;         
       }
    }
    if (a == b)
        return a;
    return res;
}


int main(){
   int e,p,q;
   char a,b,c,d;
   cout << "Input e, p, and q:";
   cin >> e >> p >> q;
   if (gcd(e,(p-1)*(q-1)) == 1){
       cout << "Input four uppercase letters:";
       cin >> a >> b >> c >> d;
       int n1 = encode(char_to_number(a),e,p*q);
       int n2 = encode(char_to_number(b),e,p*q);
       int n3 = encode(char_to_number(c),e,p*q);
       int n4 = encode(char_to_number(d),e,p*q);
       cout << "The encoding of " << a << b << c << d << " is " << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
   }
   else {
       cout << "GCD of e and (p-1)*(q-1) is not 1\n";
   }
}
