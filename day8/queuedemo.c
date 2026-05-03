//Program to implement queue using Arrays
#include <stdio.h>
#include <stdlib.h>
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

int main(){
	queue *myQueue = createQueue(3);
	return 0;
}