
// contains functions for basic operations on stack when the dataype is a pointer.
//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)

// stack : Array of pointers(to node).
// max : integer variable denoting maximum size of array.
// stackPointer : Integer variable which denotes the top index of the stack, -1 when the stack is empty.
// (*stackPointer) = Pointer to the integer variable denoting top index.
// Pointers have been used as the function will update the top index of the stack.
// value : Pointer to node dataype - root of the subtree to be pushed.

//structure to store each node of a binary tree.
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

// used to insert a value into the stack.
// return : void
void push(node* stack[], int max, int *stackPointer, node* value)
{
    if(*stackPointer == max - 1) printf("Overflow");                    //check overflow
    else stack[++(*stackPointer)]=value;                                //otherwise assign
}

// deletes the top value from stack and updates *stackPointer.
// return : void.
void pop(node* stack[], int max, int *stackPointer)
{
    if(*stackPointer == - 1 ) printf("Underflow");                      //check underflow
    else --(*stackPointer);                                             //otherwise assign
}

// to check whether stack is empty or not by the value of *stackPointer.
// return : 1 when stack is empty and 0 when it isn't
int isEmpty(node* stack[], int max, int stackPointer)                   
{
    if(stackPointer == - 1 ) return 1;                                  
    else return 0;
}

// checks whether stack is full or not.
// return : 1 when stack is full and 0 when it isn't.
int isFull(node* stack[], int max, int stackPointer)
{
    if(stackPointer == max - 1) return 1;
    else return 0;
}

// gives the top element of the stack.
// return : Pointer to root of the subtree at the top of the stack.
node* top(node* stack[], int max, int stackPointer)
{
    if(stackPointer != - 1 )
    	return stack[stackPointer];
    struct node *temp = NULL;
    return temp;
}
