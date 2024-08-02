
#include "tree.h"

t_tree *make_tree()
{
	t_tree *new_tree;

	new_tree = malloc(sizeof(t_tree));
	new_tree->root = NULL;
	return new_tree;
}

t_tree *make_tree_from_matrix(t_treeval *arr)
{
	if (NULL == arr) return make_tree();

	size_t i = 0;
	t_tree *new_tree = make_tree();

	while (arr[i])
	{
		tree_update(new_tree, arr[i++], "aber");
	}
	return new_tree;
}
