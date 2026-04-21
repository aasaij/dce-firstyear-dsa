#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data; //4
	struct Node *next; // 8
};
int main(){
	struct Node *x, *y, *z;
	x = (struct Node *)malloc(sizeof(struct Node));
	y = (struct Node *)malloc(sizeof(struct Node));
	z = (struct Node *)malloc(sizeof(struct Node));
	x->data= 10;
	x->next = y;
	y->data = 22;
	y->next = z;
	z->data = 33;
	z->next = NULL;
	return 0;
}