#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data; //4
	struct Node *next; // 8
}node;
node *createNode(int value){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp->next = NULL;
	return temp;
}
node* addFirst(node* head, int value){
	node* newNode = createNode(value);
	newNode->next = head;
	head = newNode;
	return head;
}
int main(){
	node *head = NULL;
	head = addFirst(head, 11)
	head = addFirst(head, 22);
	head = addFirst(head, 33);	
	return 0;
}