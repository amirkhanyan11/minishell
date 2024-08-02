
#include "tree.h"

static void __postorder__(tree_node *node, fptr foo)
{
	if(node == NULL || foo == NULL)
		return ;
	__postorder__(node->left, foo);
	__postorder__(node->right, foo);
	foo(node);
}

void postorder(t_tree *tree, fptr foo)
{
	__postorder__(tree->root, foo);
}
