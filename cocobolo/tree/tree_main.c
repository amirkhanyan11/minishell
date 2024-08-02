

#include "tree.h"

int main(int ac, char **av, char **envp)
{
	// int arr[] = {8, 1, 2, 9, 6, 55, 4, 7, 5, 3};
	//   int size = sizeof(arr) / sizeof(int);

	t_tree *tree = make_tree_from_matrix(envp);
	int i = 0;
	while (envp[i])
	{
		i++;
	}
	// t_tree *tree = make_tree();
	// tree_update(tree, "first", "a");
	// tree_update(tree, "second", "d");
	// tree_update(tree, "q", "gool");
	// // tree_update(tree, "masha", "tyom");

	print_tree_inorder(tree);

	return 0;
}

