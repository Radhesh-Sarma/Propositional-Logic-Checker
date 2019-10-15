//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)

#include <stdio.h>
#include <string.h>
#include "day1.h"
#include "day2.h"

void infixToPostfix(char infix_exp[])
{
    // prints the postfix expression.
    // infix_exp : character array containing infix string. 
    // return : void.
    
	int len = strlen(infix_exp); // Length of the input character array
    int stackPointer = -1; // Initialize the stack pointer to -1
    char stack[len]; // Declare the stack

    for(int i = 0; i < len; i++)
    {
        char temp = infix_exp[i];
        if((temp != '(') && (temp != ')') && (temp != '~') && (temp != '^') && (temp != '>') && (temp != 'V'))
        {
            // Check if the scanned operator is an operand and output it
            printf("%c", temp);
        }
        else if(temp != ')')
        {
            // Check if the scanned character is a ')' or not and push it to the stack
            push(stack, len, &stackPointer, temp);
        }
        else
        {
            while(top(stack, len, stackPointer) != '(')
            {
                // print the top element of the stack if the scanned character is '(' , until a '(' is found
                printf("%c", top(stack, len, stackPointer));
                pop(stack, len, &stackPointer);
            }
            pop(stack, len, &stackPointer); //remove the '(' from the top of the stack
        }  
    }
    
    while(isEmpty(stack,len,stackPointer) == 0)
    {
        //pop all the leftover elements of the stack 
        printf("%c", top(stack, len, stackPointer));
        pop(stack, len, &stackPointer);
    }
}
