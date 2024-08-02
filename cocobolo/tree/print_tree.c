
#include "tree.h"

static void __print_val__(tree_node *root)
{
	printf("%s\n", root->val);
}

void print_tree_preorder(t_tree *tree)
{
	preorder(tree, __print_val__);
	printf("\n");
}

void print_tree_inorder(t_tree *tree)
{
	inorder(tree, __print_val__);
	printf("\n");
}

void print_tree_postorder(t_tree *tree)
{
	postorder(tree, __print_val__);
	printf("\n");
}
