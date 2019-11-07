#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "parse_tree.h"
#include "day1.h"
#include "day2.h"

// contains main driver function to transform a postfix 
// propositional logic formula into equivalent formula
// in Negation Normal Form and print it.
// author: Rashi Jain, 30/10/19
int main()
{
	char post_exp[100];
	//scan the postFix expression
	scanf("%s", post_exp);
	//get the root of the parse tree.
	node* root = parseTree(post_exp);
	//get root of the modified parse tree not containing any implication. 
	root = impl_free(root);
	//get root of the modified parse tree in NNF. 
	root = nnf(root);
	//prints the infix expression through inorder traversal.
	inorder(root);
	return 0;
}