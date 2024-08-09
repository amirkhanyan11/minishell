
#include "tree.h"

bool tree_empty(t_tree *tree)
{
	return (NULL == tree || tree->NIL == tree->root);
}
