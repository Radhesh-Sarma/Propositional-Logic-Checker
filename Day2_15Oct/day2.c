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
	int len = strlen(infix_exp), stackPointer = -1;
	char stack[len];
	for(int i = 0; i < len; i++)
	{
		char temp = infix_exp[i];
		if(temp != '(' && temp != ')' && temp != '~' && temp != 'V' && temp != '^' && temp != '>')
			printf("%c", temp);
		else if(temp != ')')
			push(stack, len, &stackPointer, temp);
		else
		{
			while(top(stack, len, stackPointer) != '(')
			{
				printf("%c", top(stack, len, stackPointer));
				pop(stack, len, &stackPointer);
			}
			pop(stack, len, &stackPointer);
		}
	}
	printf("\n");
}
