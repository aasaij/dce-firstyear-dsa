//Program to imlement bubble sort algorithm
#include <stdio.h>
void bubbleSort(int a[], int n){
	for (int i = 1; i<=n; i++){
		for (int j =0; j<n-i;j++){
			if (a[j]>a[j+1]){
				//swapping of both elements
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		
	}
}
void printArray(int a[], int n){
	for (int i=0; i<n; printf("%d ", a[i++]));
}

int main(){
	int arr[] = {7,3,6,2,23,5,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, size);
	printArray(arr, size);
	return 0;
}