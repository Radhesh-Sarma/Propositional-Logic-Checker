#include<stdio.h>
#include "modifiedDay1.h"
#include "day3.h"

// main program to construct a parse tree from postfix expression
// and prints the infix expression 
// author: Rashi Jain, 11/10/19

int main()
{
	char post_exp[100];
	//scan the postFix expression
	scanf("%s", post_exp);
	//get the root of the parse tree.
	node* root = parseTree(post_exp);
	//prints the infix expression through inorder traversal.
	inorder(root);
	return 0;
}