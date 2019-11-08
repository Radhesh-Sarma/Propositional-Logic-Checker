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

node *cnf(node *root)
{
    char temp = root->ch;
    
	if(temp != '^' && temp != 'V' && temp != '>' && temp != '~')
		return root; //Check if it is an Propositional Atom 

    else if(temp == '^')
    {
         //if the expression is of the form P ^ Q , then return CNF(P) ^ CNF(Q)
        cnf(root->left);
        cnf(root->right);
    }
    else if(temp == 'V')
    {
        //if the expression is of the form P V Q , then return DISTR(CNF(P),CNF(Q))
         
         root = distr(cnf(root->left),cnf(root->right));
    }


    return root;

}

node *distr(node *n1, node *n2)
{

    char temp1 = n1->ch;
    if(temp1 == '^')
    {
        // if n1 is of the form n11 ^ n12 return DISTR(n11,n2) ^ DISTR(n12,n2) 
        struct node *pp = (struct node *)malloc(sizeof(struct node));
        pp->ch = '^';
        pp->left = distr(n1->left,n2);
        pp->right = distr(n1->right,n2);
        return pp;
    }

    char temp2 = n2->ch;

    if(temp2 == '^')
    {
        // if n2 is of the form n21 ^ n22 return DISTR(n1,n21) ^ DISTR(n1,n22)
        struct node *pp = (struct node *)malloc(sizeof(struct node));
        pp->ch = '^';
        pp->left = distr(n1,n2->left);
        pp->right = distr(n1,n2->right);
        return pp;
    }

    // Since there are no conjunctions return n1 V n2 
    struct node *pp = (struct node *)malloc(sizeof(struct node));
    pp->ch = 'V';
     pp->left = n1;
     pp->right = n2;

     return pp;           

}

