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

node *nnf(node *root)
{
	char temp = root->ch;
	if(temp != '^' && temp != 'V' && temp != '>' && temp != '~')
		return root; //Check if it is an Propositional Atom 
	else if(temp == '~' && root->right->ch != '^' && root->right->ch != 'V' && root->right->ch != '>' && root->right->ch != '~')
		return root; //Check if expression is of the form ~p 
	else if(temp == '~' && root->right->ch == '~') //Check for double negation
	{
		*root = *(root->right->right); //Remove double negation
		nnf(root);
	}
    else if(temp == '^' || temp == 'V') //if the expression is of the form P1 V P2 OR P1 ^ P2
    {
    	nnf(root->left);
    	nnf(root->right);
	}
	else //if the expression is of the form ~(P1 V P2) OR ~(P1 ^ P2)
	{
		//shift root->right to root, i.e., delete the node with ~
		root->ch = root->right->ch;
		root->left = root->right->left;
		root->right = root->right->right;
		if(root->ch == 'V') //change ch to ^ by de Morgan's law
			root->ch = '^';
		else				//change ch to V by de Morgan's law
			root->ch = 'V';
		//make two nodes pp1, pp2 to apply de Morgan's law
		struct node *pp1 = (struct node *)malloc(sizeof(struct node));
		struct node *pp2 = (struct node *)malloc(sizeof(struct node));
		pp1->ch = '~';
		pp2->ch = '~';
		pp1->left = NULL;
		pp2->left = NULL;
		pp1->right = root->left;
		pp2->right = root->right;
		root->left = pp1;
		root->right = pp2;
		//apply NNF on the new subtrees
		nnf(root->left);
    	nnf(root->right);
	}
    return root;
}
