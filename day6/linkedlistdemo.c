#include <stdio.h>
#include <stdlib.h>
typedef enum boolean {false, true} boolean;

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
		printf("\n");
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
boolean search(node* head, int element){
	if (head!=NULL){
		for (node* temp = head;temp!=NULL; temp = temp->next){
			if (temp->data == element)
				return true;
		}	
	}
	return false;
}
node* addAt(node* head, int value, int position){
	if (position == 0 || position == 1)
		return addFirst(head, value);
	//checking the following conditions
	//1. The position should be >= 2
	//2. The list should not be emtpy
	//3. The list should contain atleast two elements
	if(position > 1 && head!=NULL && head->next!=NULL){
		node* temp=head;
		for (int i = 2;i<position && temp->next!=NULL; i++)			
			temp = temp->next;
		if (temp->next!=NULL){
			//temp is not pointing the last node
			node* newNode = createNode(value);
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	return head;
}
node* deleteAt(node* head, int position){
	if (position == 0 || position == 1){
		//first node should be deleted
		return deleteFirst(head);
	}
	//checking the following conditions
	//1. The position should be >= 2
	//2. The list should not be emtpy
	//3. The list should contain atleast two elements
	if(position > 1 && head!=NULL && head->next!=NULL){
		node* temp=head;
		for (int i = 2;i<position && temp->next!=NULL; i++)			
			temp = temp->next;
		if (temp->next!=NULL){
			node* temp2 = temp->next;
			temp->next = temp2->next;
			free(temp2);
		}
	}
	return head;
}
node *reverse(node* head){
	node *prev, *current, *next;
	for (prev=NULL, next=NULL, current=head; current!=NULL;current=next){
		next = current->next;
		current->next = prev;
		prev = current;
	}
	return prev;
}
void printReverse(node* head){
	if(head==NULL)
		return;
	printReverse(head->next);
	printf("%d ", head->data);
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
	head = addAt(head, 15, 3);
	printList(head);
	head = addAt(head, 10, 5);
	printList(head);
	head = addAt(head, 10, 1);
	printList(head);	
	head = deleteAt(head, 3);
	printList(head);	
	head = deleteAt(head, 4);
	printList(head);		
	head = deleteAt(head, 4);
	printList(head);	
//	head = reverse(head);
//	printList(head);	
	printReverse(head);
//	if (search(head, 24))
//		printf("\nFound");
//	else
//		printf("\nNot Found");
	return 0;
}

//
//1. Iterative method
//2. Recursive method