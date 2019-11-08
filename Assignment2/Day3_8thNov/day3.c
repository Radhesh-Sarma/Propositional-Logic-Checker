//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parse_tree.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"

node *distr(node *n1, node *n2)
{
	if(n1->ch == '^') //if n1 is of the form n11 ^ n12 return distr(n11,n2)^distr(n12,n2) 
	{
		struct node *pp = (struct node *)malloc(sizeof(struct node));
		pp->ch = '^';
		pp->left = distr(n1->left, n2);
		pp->right = distr(n1->right, n2);
		return pp;
	}
	else if(n2->ch == '^') //if n2 is of the form n21 ^ n22 return distr(n1,n21)^distr(n1,n22)
	{
		struct node *pp = (struct node *)malloc(sizeof(struct node));
		pp->ch = '^';
		pp->left = distr(n1, n2->left);
		pp->right = distr(n1, n2->right);
		return pp;
	}
	else //since there are no conjunctions, return n1 V n2 
	{
		struct node *pp = (struct node *)malloc(sizeof(struct node));
		pp->ch = 'V';
		pp->left = n1;
		pp->right = n2;
		return pp;
	}
}

node *cnf(node *root)
{
	if(root->ch != '^' && root->ch != 'V' && root->ch != '>') //if subtree represents a literal, i.e., p or ~p
		return root;
	else if(root->ch == '^') //if the expression is of the form p^q , then return cnf(p)^cnf(q)
	{
		cnf(root->left);
		cnf(root->right);
	}
	else //if the expression is of the form pVq , then return distr(cnf(p), cnf(q))
	{
		*root = *distr(cnf(root->left), cnf(root->right));
	}
	return root;
}
