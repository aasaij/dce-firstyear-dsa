//Insertion Sort
#include <stdio.h>
void insertionSort(int a[], int n){
	for (int i = 1;i<n; i++){
		int key = a[i], j;
		for(j = i-1;key < a[j] && j>=0; j--){
			if ( key < a[j]){
				a[i]= a[j];
			}
		}
		a[j+1] = key;
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
	insertionSort(arr, n);
	printArray(arr, n);	
	return 0;
}