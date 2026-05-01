//Program to implement stack operatins using array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//defining the stack
typedef struct Stack{
	int capacity;
	int size;
	int *elements;
}stack;
stack *createStack(int max){
	stack *temp = malloc(sizeof(stack))	;
	temp->capacity = max;
	temp->size = -1;
	temp->elements = malloc(sizeof(int) * max);
	return temp;
}
bool isEmpty(stack *st){
//	method 1
//	if (st->size == -1)
//		return true;
//	else
//		return false;
	//method 2
//	return st->size == -1?true:false;
//	method 3 --> code optimization
	return st->size == -1;
}
bool isFull(stack *st){
//	if (st->size == st->capacity-1)
//		return true;
//	return false;
	return st->size+1 == st->capacity;
}
bool push(stack *st, int element){
	if (isFull(st))
		return false;
//	st->size++;
//	st->elements[st->size] = element;
	st->elements[++st->size] = element;
	return true;
}
int *pop(stack *st){
	if (isEmpty(st))
		return NULL;
	return &st->elements[(st->size)--];
}
int *top(stack *st){
	if (isEmpty(st))
		return NULL;
	return &st->elements[st->size];	
}
int stackSize(stack *st){
	return st->size+1;
}
void printMenu(){
	printf("\nStack operations demo App\n");
	printf("*************************\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Top element\n");
	printf("4. Stack size\n");
	printf("5. Display Stack\n");
	printf("6. Exit\n");
	printf("Enter your choice : ");
}
void displayStack(stack *st){
	for (int i = st->size; i>=0; i--)
		printf("%d ", st->elements[i]);
}
int main(){
	//stack operations testing
	int stSize;
	scanf("%d", &stSize);
	stack *myStack = createStack(stSize);
	while(1){ //infinite loop -> 1 - means true
		printMenu();
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				int element;
				scanf("%d", &element);
				if (push(myStack, element))
					printf("Pushed...\n");
				else
					printf("Stack overflow...\n");
				break;
			}
			case 2:{
				int *element = pop(myStack);
				if (element){//element is not NULL
					printf("%d", *element);
				}
				else // element is not there
					printf("Stack underflow...\n");
				break;
			}
			case 3:{
				int *element = top(myStack);
				if (element){//element is not NULL
					printf("%d", *element);
				}
				else // element is not there
					printf("Stack underflow...\n");				
				break;
			}
			case 4:
				printf("Stack Size : %d\n", stackSize(myStack));
				break;
			case 5:
				displayStack(myStack);
				break;
			default:
				printf("Thank you so much for being very attentive even in holidays!");
				return 0; //terminate the program
				
		}
	}
	return 0;
}