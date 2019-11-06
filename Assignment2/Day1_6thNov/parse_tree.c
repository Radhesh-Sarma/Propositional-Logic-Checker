// contains functions to construct a parse tree and print the infix expression.
//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"
#include "parse_tree.h"
// prints the infix expression via inorder traversal.
// root : Pointer to root of the binary tree. (dataype : node *)
// return : void

void inorder(node *root)
{
    if(root->right!=NULL)
    	printf("(");                  //if right is NULL, it must be a atom, so no parentheses required
    if(root->left!=NULL)
    	inorder(root->left);           //print left subtree
    printf("%c", root->ch);                             //print char of current node
    if(root->right!=NULL)
    	inorder(root->right);         //print right subtree
    if(root->right!=NULL)
    	printf(")");                  //if right is NULL, it must be a atom, so no parentheses required
}
// constructs the binary tree given a postfix expression.
// post_exp : character array containing postfix expression.
// return : (node *) dataype - pointer to the root of the binary tree.
node* parseTree(char post_exp[])
{
    int stackPointer = -1, max=strlen(post_exp);                            //initialised stack variables
    struct node * stack[max];                                               //made stack
    for(int i=0; i<max; i++)                                   //looping over all chars
    {                                               
        char temp=post_exp[i];         
        struct node* pp=(struct node *)malloc(sizeof(struct node));     //new node
        pp->ch=temp;                                                    //setting char in node
        pp->left=pp->right=NULL;                                     	//char at position i
        if((temp!='~') && (temp!='V') && (temp!='^') && (temp!='>'))    //to check if temp is operand
        {
            push(stack, max, &stackPointer, pp);                        //push in stack
        }
        else if(temp!='~')                                                  //Only if operator is not unary
        {
            struct node* right = top(stack, max, stackPointer);              //getting right child from top of stack
            pop(stack, max, &stackPointer);                                 //Popping from stack 
            struct node* left = top(stack, max, stackPointer);               //getting left child from top of stack
            pop(stack, max, &stackPointer);                                 //popping
            pp->left = left;                                                  //assigning left child
            pp->right = right;                                                //assigning right child
            push(stack, max, &stackPointer, pp);                           //pushing pp
        }
        else                                                                //Only '~' reaches here(only unary operator)
        {
            struct node* child = top(stack, max, stackPointer);              //getting only child
            pop(stack, max, &stackPointer);                                 //popping from stack    
            pp->right = child;                                                //setting child as right child to display properly
            push(stack, max, &stackPointer, pp);                           //pushing new node in stack
        }
    }
    return top(stack, max, stackPointer);
}
