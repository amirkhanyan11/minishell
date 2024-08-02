
#include "tree.h"

t_tree *make_tree()
{
	t_tree *new_tree;

	new_tree = malloc(sizeof(t_tree));
	new_tree->root = NULL;
	return new_tree;
}

t_tree *make_tree_from_array(int *arr, const int size)
{
	if (NULL == arr) return make_tree();

	size_t i = 0;
	t_tree *new_tree = make_tree();

	while (i < size)
	{
		insert_node(new_tree, arr[i++]);
	}
	return new_tree;
}
