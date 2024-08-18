
#include "tree.h"

static void	__postorder__(t_tree *tree, tree_node *node, fptr foo)
{
	if (node == tree->NIL || foo == NULL)
		return ;
	__postorder__(tree, node->left, foo);
	__postorder__(tree, node->right, foo);
	foo(node);
}

void	postorder(t_tree *tree, fptr foo)
{
	__postorder__(tree, tree->root, foo);
}
