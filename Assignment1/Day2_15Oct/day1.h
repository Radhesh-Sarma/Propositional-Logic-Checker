// contains functions for basic operations on stack.
// author : Rashi Jain, 11/10/19

// stack : character array used for implementation.
// max : integer variable denoting maximum size of array.
// stackPointer : Integer variable which denotes the top index of the stack, -1 when the stack is empty.  
// (*stackPointer) = Pointer to the integer variable denoting top index.  
// Pointers have been used as the function will update the top index of the stack.
// value : is a character variable - the value to be pushed.

// used to insert a value into the stack.
// return : void
void push(char stack[], int max, int *stackPointer, char value);

// deletes the top value from stack and updates *stackPointer.
// return : void.
void pop(char stack[], int max, int *stackPointer);

// to check whether stack is empty or not by the value of *stackPointer. 
// return : 1 when stack is empty and 0 when it isn't
int isEmpty(char stack[], int max, int stackPointer);

// checks whether stack is full or not. 
// return : 1 when stack is full and 0 when it isn't. 
int isFull(char stack[], int max, int stackPointer);

// gives the top element of the stack.
// return : character at the top of the stack. 
char top(char stack[], int max, int stackPointer);

//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)


