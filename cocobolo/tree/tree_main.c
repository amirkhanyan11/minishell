

#include "tree.h"

int main()
{
	int arr[] = {8, 1, 2, 9, 6, 55, 4, 7, 5, 3};
	const int size = sizeof(arr) / sizeof(int);

	t_tree *tree = make_tree_from_array(arr, size);
	print_tree_preorder(tree);
	node_clear(tree, 8);
	print_tree_preorder(tree);
	node_clear(tree, 7);
	print_tree_preorder(tree);
	return 0;
}

