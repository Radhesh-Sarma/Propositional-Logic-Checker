// contains function to convert any implication free formula into an equivalent one in negation normal form. 
// author : Rashi Jain, 30/10/19

// Computes Negation normal form.   
// root : Pointer to root of the parse tree(dataype : node *)
// node dataype is defined as
// typedef struct node
// {
//		char ch;  	
//   	struct node *left;
//		struct node *right;
// }node;
// return : root of the parse tree in Negation normal form(dataype : node *)
node *nnf(node *root);