
#include "tree.h"

bool tree_empty(t_tree *tree)
{
	return (NULL == tree || NULL == tree->root);
}