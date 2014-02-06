#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

//global bst node structure
struct btnode {
	int data;
	struct btnode *left;
	struct btnode *right;
};

//function prototypes
struct btnode *createNode(int data);
void insertNode(struct btnode *new,struct btnode *root);
void printInOrder(struct btnode *root);
void printPreOrder(struct btnode *root);
int sizeTree(struct btnode *root);
int maxHeight(struct btnode *root);
void minValue(struct btnode *root);
void maxValue(struct btnode *root);
void deallocateTree(struct btnode *root);

#endif