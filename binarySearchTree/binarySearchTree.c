//binarySearchTree.c
//Created by Eric Brunton on 2/4/2014

#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"

int main(int argc, char *argv[])
{
	struct btnode *root = (struct btnode*)malloc(sizeof(struct btnode));
	struct btnode *new = (struct btnode*)malloc(sizeof(struct btnode));
	int i = 0, data = 0,g = 0;
	printf("How many nodes would you like to enter into the tree? ");
	scanf("%d",&i);
	
	//create root
	if(i > 0)
	{
		printf("Enter in data for a new node: ");
		scanf("%d",&data);
		root = createNode(data);
	}

	//create rest of tree
	i--;
	while(i > 0)
	{
		printf("Enter in data for a new node: ");
		scanf("%d",&data);
		new = createNode(data);
		insertNode(new,root);
		i--;
	}

	//menu system, calls functions based on option chosen by user
	i = 1;
	while(i != 0)
	{
		printf("Please enter 0, 1, 2, 3, 4, or 5 \n\t 0 - Exit \n\t 1 - Print Inorder \n\t 2 - Print Preorder \n\t 3 - Print Size \n\t 4 - Print Max Height \n\t 5 - Print Min Value \n Answer: ");
		scanf("%d",&i);

		switch(i) {
			case 1:				//Print tree inorder
				printf("\nThe contents of this Binary Search Tree in order are: ");
				printInOrder(root);
				printf("\n\n");
				break;
			case 2:				//Print tree preorder
				printf("\nThe contents of this Binary Search Tree are: ");
				printPreOrder(root);
				printf("\n\n");
				break;
			case 3:				//Print size
				g = sizeTree(root);
				printf("\nThe number of nodes in this Binary Search Tree is %d\n\n",g);
				break;
			case 4:				//Print Max Height
				g = maxHeight(root);
				printf("\nThe maximum height of this Binary Search Tree is %d\n\n",g);
				break;
			case 5:				//Print Min Value
				minValue(root);
				break;
			default:			//default: exit program
				break;
		}
	}

	//free memory created by tree
	deallocateTree(root);

	return 0;
}

//create bst node with data passed in through argument and two NULL children
struct btnode *createNode(int data)
{
	struct btnode *new = (struct btnode*)malloc(sizeof(struct btnode));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

//inserts node into the tree, if < put it on left, if >= put it on right
void insertNode(struct btnode *new,struct btnode *root)
{
	if(new->data >= root->data)
	{
		if(root->right == NULL)
		{
			root->right = new;
		}
		else
		{
			insertNode(new,root->right);
		}
	}
	else
	{
		if(root->left == NULL)
		{
			root->left = new;
		}
		else
		{
			insertNode(new,root->left);
		}
	}
}

//print tree in order, start from left subtree, print parent, then print right subtree
void printInOrder(struct btnode *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}

//print tree in pre order, start from parent, print left subtree, then print right subtree
void printPreOrder(struct btnode *root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

//return the number of nodes in the tree, add one to i for each node accessed not NULL
int sizeTree(struct btnode *root)
{
	int i = 0;
	if(root == NULL)
	{
		i = 0;
	}
	else
	{
		i += 1;
		i += sizeTree(root->left);
		i += sizeTree(root->right);
	}

	return i;
}

//returns max height of tree, if there's a node to right or left, add one to that and compare values to find max
int maxHeight(struct btnode *root)
{
	int left = 0, right = 0;
	if(root != NULL)
	{
		left = maxHeight(root->left);
		right = maxHeight(root->right);
		if(left > right)
		{
			return (left + 1);
		}
		else
		{
			return (right + 1);
		}
	}
}

//prints minimum value in the tree, find left most node in the entire tree
void minValue(struct btnode *root)
{
	if(root->left == NULL)
	{
		printf("\nThe minimum value in this Binary Search Tree is %d\n\n",root->data);
	}
	else
	{
		minValue(root->left);
	}
}

//prints maximum value in the tree, find right most node in the entire tree
void maxValue(struct btnode *root)
{
	if(root->right == NULL)
	{
		printf("\nThe maximum value in this Binary Search tree is %d\n\n",root->data);
	}
	else
	{
		maxValue(root->right);
	}
}

//frees all memory allocated from the tree, deallocate the left subtree, the right subtree, then the parent itself
void deallocateTree(struct btnode *root)
{
	if(root != NULL)
	{
		deallocateTree(root->left);
		deallocateTree(root->right);
		free(root);
	}
}