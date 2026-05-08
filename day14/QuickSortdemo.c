//Program to implement quick algorithm
#include <stdio.h>
void swap(int *x, int *y){
	*x = (*x+*y)- (*y=*x);
}
int partition(int a[], int low, int high){
	int pivot = a[low];
	int left = low, right = high;
	while(left < right)	{
		while (a[left]<=pivot)	
			left++;
		while (a[right]>pivot)
			right--;
		if (left < right)
			swap (a+left, a+right);
	}
	swap(a+low, a+right);
	return right;
}
void quickSort(int arr[], int low, int high){
	if (low < high){
		int pivotIndex = partition(arr, low, high);
		quickSort(arr, low, pivotIndex-1);
		quickSort(arr, pivotIndex+1, high);
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
	for (int i = 0; i<n; i++)
		scanf("%d", arr+i);
	quickSort(arr, 0, n-1);
	printArray(arr,n);
	return 0;
}