//Selection Sort
// Ascending order --> Find least element
// 
// Descending order -=> Find largest element
//Program to implement selection sort algorithm
#include <stdio.h>
void swap(int *x, int *y){
//	int temp = *x;
//	*x = *y;
//	*y = temp;
	*x = (*x+*y)-(*y=*x);
}
void selectionSort(int a[], int n){
	for (int i =0; i<n; i++){
		int minIndex = i;
		for (int j =i+1;j<n; j++){
			if (a[minIndex]>a[j])
				minIndex = j;
		}
		if(minIndex != i){
			swap(a+minIndex, a+i);
		}
	}
}
void printArray(int a[], int n){
	printf("\n[");
	for (int i = 0; i<n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]",a[n-1]);
}
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0;i<n;i++)
		scanf("%d", arr+i); // scanf("%d", &arr[i])
	selectionSort(arr, n);
	printArray(arr, n);	
	return 0;
}