//Program to demonstrate tree data structure
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	struct TreeNode *child1;
	struct TreeNode *child2;
	int data;
	struct TreeNode *child3;
	struct TreeNode *child4;
}tnode;
tnode* createNode(int value){
	tnode *temp = (tnode*)malloc(sizeof(tnode));
	temp->data = value;
	temp->child1 = NULL;
	temp->child2 = NULL;
	temp->child3 = NULL;
	temp->child4 = NULL;
	return temp;
}
int main(){
	tnode *root = createNode(10);
	root->child1 = createNode(20);
	root->child2 = createNode(30);
	root->child3 = createNode(40);
	root->child4 = createNode(50);
	return 0;
}
