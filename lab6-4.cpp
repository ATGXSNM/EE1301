#include <iostream>

using namespace std;

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n){
	int i;
	int j;
	for (i = 0; i < n-1; i++)
	for (j = 0; j < n-i-1; j++)
	if (arr[j] > arr[j+1])
	swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size){
	for (int i=0; i < size; i++){
		if(i%5==0 && i>0)
		cout<<endl;
		cout<< arr[i] << " ";   
		}
	cout<<endl;
}

int main(){
int arr[50];
int i=0, n=50;

for(i=0;i<50;++i){
arr[i]=100-i;
}

bubbleSort(arr, n);

cout<< "Sorted array: "<<endl;
printArray(arr, n);

return 0;
}
