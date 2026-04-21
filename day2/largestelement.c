//Program to find highest element in an array
#include <stdio.h>

int main(){
	int size;
	scanf("%d", &size);
	int arr[size];
	//reading <size> elements
	for (int index = 0; index<size;index++)
		scanf("%d", &arr[index]);
	int max = arr[0];
	for (int index = 1; index<size; index++)
		if (arr[index]>max)
			max = arr[index];
	printf("Largest : %d", max);
	return 0;
}