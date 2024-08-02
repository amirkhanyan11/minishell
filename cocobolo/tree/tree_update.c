
#include "tree.h"

static void	__insert_node__(tree_node **root, t_treeval key, t_treeval val)
{
	if (NULL == *root)
		*root = make_tree_node(key, val);
	else if (less(key, (*root)->key))
		__insert_node__(&((*root)->left), key, val);
	else if (less((*root)->key, key))
		__insert_node__(&((*root)->right), key, val);
}

void	tree_update(t_tree *tree, t_treeval key, t_treeval val)
{
	tree_pop(tree, key);
	__insert_node__(&tree->root, key, val);
}
