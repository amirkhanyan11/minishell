
#include "tree.h"

tree_node *__find_min__(t_tree *tree, tree_node *root)
{
	return (root == tree->NIL || root->left == tree->NIL) ? root : __find_min__(tree, root->left);
}

tree_node *find_min(t_tree *tree)
{
	if (!tree) return NULL;

	return __find_min__(tree, tree->root);
}
