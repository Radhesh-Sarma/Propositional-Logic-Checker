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

node *impl_free(node *root)
{
	char temp = root->ch;
	if(temp != '^' && temp != 'V' && temp != '>' && temp != '~')
		return root; // Check if it is an Propositional Atom 
	else if(temp == '~')
	{
		impl_free(root->right);
        // IMPL_FREE (~p) = ~p
        

	}
	else if(temp == 'V' || temp == '^')
	{
        // IMPL_FREE (p V q ) = IMPL_FREE(p) V IMPL_FREE(q)
        // IMPL_FREE (p ^ q ) = IMPL_FREE(p) ^ IMPL_FREE(q)
		impl_free(root->left); 
		impl_free(root->right);
	}
	else
	{
        // IMPL_FREE (p > q ) = ~IMPL_FREE(p) V IMPL_FREE(q)     
		root->ch = 'V';
		struct node *pp = (struct node *)malloc(sizeof(struct node));
		pp->ch = '~';
		pp->left = NULL;
		pp->right = root->left;
		root->left = pp;
		impl_free(root->left);
		impl_free(root->right);
	}
	return root;
}
