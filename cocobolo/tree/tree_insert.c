
#include "tree.h"

static void	__insert_node__(tree_node **root, t_treeval val)
{
	if (NULL == *root)
		*root = make_tree_node(val);
	else if (less(val, (*root)->val))
		__insert_node__(&((*root)->left), val);
	else if (less((*root)->val, val))
		__insert_node__(&((*root)->right), val);
}

void	insert_node(t_tree *tree, t_treeval val)
{
	__insert_node__(&tree->root, val);
}
