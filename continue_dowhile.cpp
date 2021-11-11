#include <iostream>
using namespace std;

int main(){
  int x=0;

  do{
    x++;
    if(x==5){
      continue;
    }
    cout << x << " ";
  }while(x<10);

  return 0;
}
