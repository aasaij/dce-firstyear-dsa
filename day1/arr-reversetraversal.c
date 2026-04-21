//Program to reverse an array
#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int index=0;index<n; index++)
		scanf("%d",&arr[index]);
	for (int index =n-1;index>=0;index-- )
		printf("%d ", arr[index]);
	return 0;
}