#include<stdio.h>
#include "modifiedDay1.h"
#include "day3.h"
#include "day4.h"

// main program to give evaluation of a postfix expression.
// author: Rashi Jain, 11/10/19
int main()
{
	char post_exp[100];
	//scan the postfix expression.
	scanf("%s", post_exp);
	//n is number of propositional variables. 
	int n;
	scanf("%d",&n);
	//var stores the propostional variables.
	char var[n];
	//value stores the value of the respective vairable.
	int value[n];
	int i = 0;
	//loop to take input of n variables and their values. 
	while(i < n)
	{
		char blank;
		scanf("%c",&blank);
		scanf("%c",&var[i]);
		scanf("%d",&value[i]);
		i++;
	}
	//get the root of the parse tree. 
	node *root = parseTree(post_exp);
	//prints the infix expression.
	inorder(root);
	//prints the final value of the parse tree given particular valuation. 
	printf("%d ", evalParseTree(root, var, value, n));
	return 0;		
}