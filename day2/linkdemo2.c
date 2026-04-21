#include <stdio.h>
struct Node{
	int data;
	struct Node *next;//structure pointer
};

int main(){
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));
	root->data = 10;
	root->next = NULL
	return 0;
}
//Dynamic Memory allocation
/* stdlib.h
malloc() & calloc() allocate memory dynamically in the heap segment
malloc()
	void* malloc(size_t numBytes)
	returns the address of the memory which is newly allocated
	returns NULL if it is insufficient memory
calloc()
	void* calloc(size_t numBlocks, size_t blockSize);
	
realloc()
	void* realloc(void* oldBlock, size_t newSizeInBytes);
free()
	void free(void* blockName);
*/