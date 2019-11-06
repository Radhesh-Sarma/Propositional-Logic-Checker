#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "parse_tree.h"
#include "day1.h"

//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)

// contains main driver function to make a postfix
// expression implication free and print its 
// infix expression. 
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
	//prints the infix expression through inorder traversal.
	inorder(root);
	return 0;
}