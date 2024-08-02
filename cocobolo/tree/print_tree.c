
#include "tree.h"

static void __print_key__(tree_node *root)
{
	printf("%s ~jupa~ %s\n", root->key, root->val);
}

void print_tree_preorder(t_tree *tree)
{
	preorder(tree, __print_key__);
}

void print_tree_inorder(t_tree *tree)
{
	inorder(tree, __print_key__);
}

void print_tree_postorder(t_tree *tree)
{
	postorder(tree, __print_key__);
}
