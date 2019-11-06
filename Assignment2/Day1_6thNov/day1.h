// contains function to make any propositional logic formula implication-free. 
// author : Rashi Jain, 30/10/19

//Team Nomenclature: A38
//1. Radhesh Sarma (2017B4A70886H)
//2. Harshit Gakhar (2018A7PS0182H)
//3. Bhavyesh Desai (2018A7PS0164H)

// Removes all implications from the parse tree.   
// root : Pointer to root of the parse tree(dataype : node *)
// node dataype is defined as
// typedef struct node
// {
//		char ch;  	
//   	struct node *left;
//		struct node *right;
// }node;
// return : root of the parse tree not containing any implication (dataype : node *)
node *impl_free(node *root);