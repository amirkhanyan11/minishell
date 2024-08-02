
#include "tree.h"

tree_node *__tree_find__(tree_node *root, t_treeval val)
{
 	if (NULL == root)
		return NULL;
	if (less(root->val, val))
		return(__tree_find__(root->right, val));
	else if (less(val, root->val))
		return(__tree_find__(root->left, val));
	else
		return root;
}

tree_node *tree_find(t_tree *tree, t_treeval val)
{
	return(__tree_find__(tree->root, val));
}
