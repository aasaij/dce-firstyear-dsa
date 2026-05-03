//Program to implement circular queue using Arrays
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Queue{
	int capacity; // 4
	int front; // 4
	int rear; // 4
	int *elements; //8
}queue;
queue *createQueue(int qSize){
	queue *temp = (queue*)malloc(sizeof(queue));
	temp->capacity = qSize;
	temp->front = -1;
	temp->rear = -1;
	temp->elements = (int*)malloc(sizeof(int)*qSize);
	return temp;
}

bool isFull(queue *q){
	if (q->rear == q->capacity-1 && q->front == 0 || q->rear+1 == q->front)
		return true;
	return false;
		
}
bool isEmpty(queue *q){
	return q->front == -1 && q->rear == -1;
}
bool enqueue(queue *q, int element){
	if (isFull(q))
		return false;
	if (q->front ==-1)
		q->front = 0;
	q->rear = (q->rear+1) % q->capacity;
	q->elements[q->rear] = element;
	return true;
}
bool dequeue(queue *q){
	if (isEmpty(q))
		return false;
	if (q->front == q->rear){
		q->front = -1;
		q->rear = -1;
	}
	else
		q->front = (q->front+1)%q->capacity;
	return true;
}
int *peek(queue *q){
	if (isEmpty(q))
		return NULL;
	return &q->elements[q->front];
}
int queueSize(queue *q){
	if (isEmpty(q))
		return 0;
	int cnt = 0;
	for (int i = q->front; i!= q->rear; i=(i+1)%q->capacity)
		cnt++;
	return cnt+1;
}
void printQueue(queue *q){
	if (!isEmpty(q)){
		for (int i = q->front; i!=q->rear; i = (i+1)%q->capacity)
			printf("%d ", q->elements[i]);
		printf("%d", q->elements[q->rear]);
	}
	else
		printf("Queue is empty!\n");
}
void printMenu(){
	printf("\nQueue operations demo App\n");
	printf("*************************\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Peek\n");
	printf("4. Queue Size\n");
	printf("5. Print queue\n");
	printf("6. Exit\n");
	printf("Enter your choice : ");
}
int main(){
	queue *myQueue = NULL;
	int qSize;
	scanf("%d", &qSize);
	myQueue = createQueue(qSize);
	while(true){ //infinite loop
		printMenu();
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				int element;
				scanf("%d", &element);
				if (enqueue(myQueue, element))
					printf("Enqueued...\n");
				else
					printf("Queue is full\n");
				break;
			}
			case 2:
				if (dequeue(myQueue))
					printf("Dequeued...\n");
				else
					printf("Queue is empty\n");
				break;
			case 3: {
				int *element = peek(myQueue);
				if (element) //element is not NULL
					printf("Top element : %d\n",*element );
				else
					printf("Queue is empty\n");
				break;
			}
			case 4:
				printf("Queue size : %d\n",queueSize(myQueue) );
				break;
			case 5:
				printQueue(myQueue);
				break;
			default:
				printf("Thank you so much for being very very active in the class");
				exit(0); //terminate the application
		}
	}
	return 0;
}