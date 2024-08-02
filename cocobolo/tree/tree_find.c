
#include "tree.h"

tree_node *__tree_find__(tree_node *root, t_treeval key)
{
 	if (NULL == root)
		return NULL;
	if (less(root->key, key))
		return(__tree_find__(root->right, key));
	else if (less(key, root->key))
		return(__tree_find__(root->left, key));
	else
		return root;
}

tree_node *tree_find(t_tree *tree, t_treeval key)
{
	return(__tree_find__(tree->root, key));
}
