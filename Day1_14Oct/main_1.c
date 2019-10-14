#include<stdio.h>
#include "day1.h"
//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)




// main program to perform operations on the stack. 
// author: Rashi Jain, 11/10/19

int main()
{
	//declare maximum number of characters in the stack. 
	int max; 
	scanf("%d", &max);
	//declare a stack of max charaters.
	char stack[max]; 
	//Initialize the pointer to point to -1 as it is empty. 
	int stackPointer = -1;
	//number of operations to be done on stack.  
	int n;  
	scanf("%d", &n);
	//for choice of operation
	int choice;
	char c;
	int x;
	//loop for n operations
	while(n--)
	{
		//take choice of operation as input from user.
		scanf("%d", &choice);  
		switch(choice)
		{
			//Push operation - to insert
			case 1: 
			scanf("%c",&c); //blank input
			scanf("%c",&c);
			push(stack, max, &stackPointer, c);
			break;

			//Pop operation - to delete the topmost element
			case 2:
			pop(stack, max, &stackPointer);
			break;

			//To check whether stack is empty or not
			case 3:
			x = isEmpty(stack, max, stackPointer);  
			if(x == 0)
				printf("false \n");
			else if( x == 1)
				printf("true \n");
			break;

			//To check whether stack is Full or not
			case 4:
			x = isFull(stack, max, stackPointer);
			if(x == 0)
				printf("false \n");
			else if( x == 1)
				printf("true \n");
			break;

			//To get the topmost element of the stack.
			case 5:
			printf("%c \n", top(stack, max, stackPointer));
			break;

			//To print the stack.
			// case 6:
			// print(stack, max, stackPointer);
			// break;
		}

	}
	return 0;
}