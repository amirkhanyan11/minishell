

#include "tree.h"

int main(int ac, char **av, char **envp)
{
	// int arr[] = {8, 1, 2, 9, 6, 55, 4, 7, 5, 3};
	//   int size = sizeof(arr) / sizeof(int);

	t_tree *tree = make_tree_from_matrix(envp);

	print_tree_inorder(tree);

	return 0;
}

