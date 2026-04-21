#include <stdio.h>
//Program to read <n> elements and print <n> elements using array
int main(){
	int n;
	scanf("%d", &n);
	int arr[n]; 
	//reading <n> elements from the user
	for (int index = 0;index<n; index++)
//		scanf("%d", &arr[index])
		scanf("%d", arr+index); // scanf("%s", name);
	//printing <n> elements from the array
	for (int index = 0; index<n; index++)
		printf("%d ", arr[index] );
//		printf("%d", *(arr+index))
	return 0;
}