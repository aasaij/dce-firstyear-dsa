#include <stdio.h>
struct Node{
	int data;
	
};
int main(){
	int x=10;
	float y;
	char z;
	void *ptr; //General purpose pointer
	ptr = &x;
	printf("%d", *(int*)ptr);
	ptr = &y;
	ptr = &z;
	return 0;
}