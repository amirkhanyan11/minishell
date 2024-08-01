
#include "tree.h"

tree_node *__search__(tree_node *root, int val)
{
 	if (NULL == root || equal(val, root->val))
		return root;
	if (greater(val, root->val))
		return(__search__(root->right, val));
	else
		return(__search__(root->left, val));
}

tree_node *search(t_tree *tree, int val)
{
	return(__search__(tree->root, val));
}
