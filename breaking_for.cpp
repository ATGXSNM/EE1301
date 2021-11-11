#include <iostream>
using namespace std;

int main(){

  int i,j;

  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
      if(i==5 && j==5){
	break;
      }
      cout << i << j << endl;
    }
    if(i==5 && j==5){
      break;
    }
  }

  return 0;

}
