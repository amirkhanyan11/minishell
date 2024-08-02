
#include "tree.h"

tree_node *make_tree_node(  t_treeval val)
{
	tree_node *new_node;
	new_node = malloc(sizeof(tree_node));
	new_node->val = NULL;
	treeval_copy(&new_node->val, &val);
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
