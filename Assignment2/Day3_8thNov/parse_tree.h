// contains functions to construct a parse tree and print the infix expression. 
// author : Rashi Jain, 11/10/19

// prints the infix expression via inorder traversal. 
// root : Pointer to root of the binary tree. (dataype : node *)
// node dataype is defined as
// typedef struct node
// {
//		char ch;  	
//   	struct node *left;
//		struct node *right;
// }node;
// return : void
void inorder(node *root);

// constructs the binary tree given a postfix expression. 
// post_exp : character array containing postfix expression.
// return : (node *) dataype - pointer to the root of the binary tree. 
node* parseTree(char post_exp[]);