//Program to imlement bubble sort algorithm
#include <stdio.h>
#include <string.h>
void bubbleSort(int n, int m, char a[n][m]){
	for (int i = 1; i<=n; i++){
		for (int j =0; j<n-i;j++){
			if (strcmp(a[j], a[j+1])>0){
				char temp[20];
				strcpy(temp, a[j]); // temp = a[j]
				strcpy(a[j],a[j+1] );
				strcpy(a[j+1], temp);
			}
		}
		
	}
}
void printArray(int n, int m, char a[n][m]){
	for (int i=0; i<n; printf("\"%s\" ", a[i++]));
}

int main(){
	char names[][20] = {"Shreya", "Abimani", "Lavanya", "Logesh","Dhivya"};
	int size = sizeof(names)/sizeof(names[0]);
	bubbleSort(size,20, names);
	printArray(size,20, names);
	return 0;
}