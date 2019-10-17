#include <stdio.h>
#include <string.h>
#include "modifiedDay1.h"
#include "day3.h"
#include "day4.h"

int evalParseTree(node *root, char var[], int value[], int n)
{
	if(root->left == NULL && root->right == NULL)
	{
		int tval;
		for(int i = 0; i < n; i++)
			if(var[i] == root->ch)
				tval = value[i];
		return tval;
	}
	else if(root->left == NULL)
	{
		int a = evalParseTree(root->right, var, value, n);
		if(a == 0)
			return 1;
		else
			return 0;
	}
	int a = evalParseTree(root->left, var, value, n);
	int b = evalParseTree(root->right, var, value, n);
	if(root->ch == 'V')
		return a|b;
	else if(root->ch == '^')
		return a&b;
	if(a == 0)
		a = 1;
	else
		a = 0;
	return a|b;
}
