// contains function to find the evaluation of a parse tree. 
// author : Rashi Jain, 11/10/19.

// calculates the evalation of a parse tree.
// root : pointer to the root of the tree. (dataype : node *)
// node dataype is defined as
// typedef struct node
// {
//		char ch;
//		struct node *left;
//		struct node *right;
// }node;
// var : character array containing all propositional variables.
// value : integer array containing 0/1 denoting the value of respective variable.
// For eg: if var[i] = 'p', then value[i] will contain the value of 'p'..
// n : number of propositional variables. 
// return : Integer value (0/1) giving the evaluation of the tree. 
int evalParseTree(node *root, char var[], int value[], int n);