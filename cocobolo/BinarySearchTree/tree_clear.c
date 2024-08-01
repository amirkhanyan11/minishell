
#include "tree.h"

void delete_node(tree_node *node)
{
	node->left = NULL;
	node->right = NULL;
	free(node);
}

void tree_clear(t_tree **treeptr)
{
	if (!treeptr || !(*treeptr)) return;

	t_tree *tree = *treeptr;
	postorder(tree, delete_node);
	tree->root = NULL;
	free(tree);
	*treeptr = NULL;

}
