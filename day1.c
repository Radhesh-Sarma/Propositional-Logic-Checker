//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)

#include<stdio.h>
#include"day1.h"
void push(char stack[], int max, int *stackPointer, char value)
{   
    // used to insert a value into the stack 
    // return : void

    if(*stackPointer + 1 == max)
    {
        printf("OverFlow"); // Check if stack is full
        return;
    }
    *stackPointer = *stackPointer + 1; // Increase stackPointer by 1
    stack[*stackPointer] = value;     // Assign the value to be added to the stack where incremented stack pointer points
}

void pop(char stack[], int max, int *stackPointer)
{
    // deletes the top value from stack and updates *stackPointer.
    // return : void.
    if(*stackPointer == -1)
    {
        printf("UnderFlow"); // check if stack is empty,then Underflow condition
        return ;
    }
    *stackPointer = *stackPointer - 1; // Decrease the stackPointer by 1
}

int isEmpty(char stack[], int max, int stackPointer)
{

    // to check whether stack is empty or not by the value of *stackPointer. 
    // return : 1 when stack is empty and 0 when it isn't

    if(stackPointer == -1) // Compare the stackPointer with -1 
    {
        return 1; // if stackPointer is -1 , then return 1 since stack is empty
    }
    else
    {
        return 0; // if stackPointer is not -1 , then return 0 since stack is non - empty
    }
}

int isFull(char stack[], int max, int stackPointer)
{
    // checks whether stack is full or not. 
    // return : 1 when stack is full and 0 when it isn't. 

    // compares the stackPointer to check the number of elements 
    if(stackPointer == max - 1)
    {
        return 1; //returns 1 in case stack is Full
    }
    else
    {
        return 0; //returns 0 in case stack is not Full 
    }
}

char top(char stack[], int max, int stackPointer)
{
    // gives the top element of the stack.
    // return : character at the top of the stack. 

    if(stackPointer == -1)
    {
        printf("Error!!! Stack is Empty");
         // Checks Underflow Condition
         return -1;
    }
    return stack[stackPointer]; // return the top element of the stack
}



