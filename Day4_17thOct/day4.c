//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)

#include <stdio.h>
#include <string.h>
#include "modifiedDay1.h"
#include "day3.h"
#include "day4.h"

//function to evaluate parse tree
int evalParseTree(node *root, char var[], int value[], int n)
{
	if(root->left == NULL && root->right == NULL) //checks if node is a propositional atom
	{
		int tval; //variable to store value of atom
		for(int i = 0; i < n; i++) //loop to find value of atom
			if(var[i] == root->ch)
				tval = value[i];
		return tval; //return value of atom
	}
	else if(root->left == NULL) //check if the operator is ~ operator
	{
		int a = evalParseTree(root->right, var, value, n); //evaluate it's only child subtree
		if(a == 0)
			return 1; //return negation of child subtree
		else
			return 0; //return negation of child subtree
	}
	//for binary operators, evaluate their left and right subtrees and store in a and b
	int a = evalParseTree(root->left, var, value, n);
	int b = evalParseTree(root->right, var, value, n);
	if(root->ch == 'V') //if the operator is OR
		return a|b; //return a OR b
	else if(root->ch == '^') //if the operator is AND
		return a&b; //return a AND b
	if(a == 0) //change a to (~a)
		a = 1;
	else
		a = 0;
	return a|b; //return a IMPLIES b using the form (NOT a) OR b
}
