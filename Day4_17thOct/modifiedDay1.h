// contains functions for basic operations on stack when the dataype is a pointer. 
// author : Rashi Jain, 11/10/19

// stack : Array of pointers(to node).
// max : integer variable denoting maximum size of array.
// stackPointer : Integer variable which denotes the top index of the stack, -1 when the stack is empty.  
// (*stackPointer) = Pointer to the integer variable denoting top index.  
// Pointers have been used as the function will update the top index of the stack.
// value : Pointer to node dataype - root of the subtree to be pushed.

//structure to store each node of a binary tree. 
typedef struct node
{
	// character value of a node.
	char ch;
	// Pointer to left subtree of the node.
	struct node *left;
	// Pointer to right subtree of the node. 
	struct node *right;
}node; //structure typedef as 'node'.

// used to insert a value into the stack.
// return : void
void push(node* stack[], int max, int *stackPointer, node* value);

// deletes the top value from stack and updates *stackPointer.
// return : void.
void pop(node* stack[], int max, int *stackPointer);

// to check whether stack is empty or not by the value of *stackPointer. 
// return : 1 when stack is empty and 0 when it isn't
int isEmpty(node* stack[], int max, int stackPointer);

// checks whether stack is full or not. 
// return : 1 when stack is full and 0 when it isn't. 
int isFull(node* stack[], int max, int stackPointer);

// gives the top element of the stack.
// return : Pointer to root of the subtree at the top of the stack. 
node* top(node* stack[], int max, int stackPointer);
