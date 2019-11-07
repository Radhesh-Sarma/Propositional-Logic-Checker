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
    char temp = root -> ch;


    	if(temp != '^' && temp != 'V' && temp != '>' && temp != '~')
		    {
                return root; // Check if it is an Propositional Atom 
            }
        else if(temp == '^' || temp == 'V')
        {

           root -> left = nnf(root->left);
            root -> right = nnf(root->right);
        }
        else if(temp == '~')
        {
            if((root->right)->ch =='~')
            {
                root = nnf((root->right)->right);
            }
            else
            {
              // Bhavyesh or Harshit do it 
               
            }
            
        }

    return root;
}