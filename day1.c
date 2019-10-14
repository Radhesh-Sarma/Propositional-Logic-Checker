//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)

#include <stdio.h>

void push(char stack[], int max, int *stackPointer, char value)
{
	*stackPointer = *stackPointer + 1; //increase stackPointer by 1
	stack[*stackPointer] = value; //add value to top of stack
}

void pop(char stack[], int max, int *stackPointer)
{
	*stackPointer = *stackPointer - 1; //decrease stackPointer by 1
}

int isEmpty(char stack[], int max, int stackPointer)
{
	if(stackPointer == -1)	//if stack is empty
		return 1;			//return 1
	return 0;				//else return 0
}

int isFull(char stack[], int max, int stackPointer)
{
	if(stackPointer == max-1)	//if stack is full
		return 1;				//return 1
	return 0;					//else return 0
}

char top(char stack[], int max, int stackPointer)
{
	return stack[stackPointer];	//return top element of stack
}
