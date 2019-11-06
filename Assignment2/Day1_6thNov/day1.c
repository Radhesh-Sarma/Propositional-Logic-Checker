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
		return root;
	else if(temp == '~')
	{
		impl_free(root->right);
	}
	else if(temp == 'V' || temp == '^')
	{
		impl_free(root->left);
		impl_free(root->right);
	}
	else
	{
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
