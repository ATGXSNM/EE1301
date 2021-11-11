#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int* randfun_alloc(int n){
	srand (time(NULL));
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	arr[i]=rand()%1000;
	
  
	return arr;
}

int main(){
	int n;
	cout<<"How many number that your want to take for array : "<<endl;
	cin>>n;
	int *arr =randfun_alloc(n);
  
	for(int i=0;i<n;i++){
	cout<<arr[i]<<" ";
	}
  
	cout<<endl;
	delete[] arr;
	return 0;
} 
