
#include "tree.h"

tree_node *__find_min__(tree_node *root)
{
	return (root == NULL || !root->left) ? root : __find_min__(root->left);
}

tree_node *find_min(t_tree *tree)
{
	if (!tree) return NULL;

	return __find_min__(tree->root);
}
