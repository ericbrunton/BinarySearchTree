#Binary Search Tree

### Description
This program uses structures in the language C to create a Binary Search Tree data structure.

Is used through a menu system (switch) to call functions and print results.

### Functions
- createNode
	- Allocates memory for a node struct and initializes the data within the structure.
- insertNode
	- Inserts a node struct into the existing tree.
- printInOrder
	- Prints the contents of the tree in order, starting from least to greatest.
- printPreOrder
	- Prints the contents of the tree by a node followed by its left child and then right child, recursively.
- sizeTree
	- Determines and returns the number of node structs within the tree.
- maxHeight
	- Determines and returns the maximum height of the tree from root to leaf.
- minValue
	- Finds and prints the node with the minimum value within the tree.
- deallocateTree
	- Deallocates and frees all memory that was allocated when each node struct was created.