
#include "tree.h"
#include <cocobolo.h>

void delete_node(tree_node *node)
{
	__delete_string(&node->key);
	__delete_string(&node->val);
	node->left = NULL;
	node->right = NULL;
	free(node);
}

void tree_clear(t_tree **treeptr)
{
	if (!treeptr || !(*treeptr)) return;

	t_tree *tree = *treeptr;
	postorder(tree, delete_node);
	delete_node(tree->NIL);
	tree->NIL = NULL;
	tree->root = NULL;
	free(tree);
	*treeptr = NULL;
}
