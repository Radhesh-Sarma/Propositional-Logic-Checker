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
        cnf(root->left);
        cnf(root->right);
    }
    else if(temp == 'V')
    {
         root = distr(cnf(root->left),cnf(root->right));
    }


    return root;

}

node *distr(node *n1, node *n2)
{

    char temp1 = n1->ch;
    if(temp1 == '^')
    {
        struct node *pp = (struct node *)malloc(sizeof(struct node));
        pp->ch = '^';
        pp->left = distr(n1->left,n2);
        pp->right = distr(n1->right,n2);
        return pp;
    }

    char temp2 = n2->ch;

    if(temp2 == '^')
    {
        struct node *pp = (struct node *)malloc(sizeof(struct node));
        pp->ch = '^';
        pp->left = distr(n1,n2->left);
        pp->right = distr(n1,n2->right);
        return pp;
    }

    struct node *pp = (struct node *)malloc(sizeof(struct node));
    pp->ch = 'V';
     pp->left = n1;
     pp->right = n2;

     return pp;           

}

