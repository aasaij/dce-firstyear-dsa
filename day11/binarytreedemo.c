//Program to demonstrate binary tree
#include <stdio.h>
#include <stdlib.h>
//definition of binary tree node
typedef struct BTNode {
	struct BTNode *left;
	char value;
	struct BTNode *right;
}node;
node* createNode(char value){
	node* temp = (node*)malloc(sizeof(node));
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
//Depth First Search - Tree Traversal
void preorder(node* root){
	if (root){ // if root is not null
		printf("'%c' ", root->value);
		preorder(root->left);
		preorder(root->right);		
	}
}
void inorder(node* root){
	if (root){
		inorder(root->left);
		printf("'%c' ", root->value);
		inorder(root->right);
	}
}
void postorder(node* root){
	if (root){
		postorder(root->left);
		postorder(root->right);
		printf("'%c' ", root->value);
	}
}
int main(){
	node* root = createNode('A');
	root->left = createNode('B');
	root->right = createNode('C');
	root->left->left = createNode('D');
	root->left->right = createNode('E');
	root->right->left = createNode('F');
	root->right->right = createNode('G');
	printf("\nInorder Traversal : ");
	inorder(root);
	printf("\nPreorder Traversal : ");
	preorder(root);
	printf("\nPostorder Traversal : ");
	postorder(root);
	return 0;
}