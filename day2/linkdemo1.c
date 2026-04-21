#include <stdio.h>
struct Node{
	int data;
	struct Node *next;//structure pointer
};

int main(){
	struct Node x,y,z;
	x.data =10;
	x.next = &y;
	y.data = 20;
	y.next = &z;
	z.data = 30;
	z.next = NULL;
	return 0;
}