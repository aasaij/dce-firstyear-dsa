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
node *addLast(node *head, int value){
	node* newNode = createNode(value);
	if (!head)//checking whether the list is empty
		return newNode;
	node* temp;
	for (temp = head;temp->next != NULL; temp= temp->next);
	temp->next = newNode;
	return head;
}
void printList(node* head){
	if(head){
		//the list is not empty
		printf("\n");
		for (node* temp = head; temp!=NULL; temp=temp->next)
			printf("%d ", temp->data);
	}
	else
		printf("\n[]\n");
}
node *deleteFirst(node* head){
	if (head){
		//list is not empty
		node* temp = head;
		//move the head pointer to the next node
		head = temp->next;
		//delete the first node
		free(temp);
	}
	return head;
}
node *deleteLast(node* head){
	if (head){
		//list is not empty
		if (head->next==NULL){
			//list contains only one element
			//removing the element and returning NULL
			free(head);
			return NULL;
		}
		node* temp;
		//move the temp pointer to the last but second node
		for (temp=head; temp->next->next!=NULL; temp=temp->next);
		free(temp->next);
		temp->next= NULL;
	}
	return head;
}
int main(){
	node *head = NULL;
	head = addFirst(head, 11);
	head = addFirst(head, 22);
	head = addFirst(head, 33);	
	printList(head);
	head = addLast(head, 44);
	head = addLast(head, 55);
	printList(head);
	head = deleteFirst(head);
	printList(head);
	head = deleteLast(head);
	printList(head);
	return 0;
}