#include "tree.h"


static tree_node *__node_clear__(tree_node *root,   t_treeval val)
{
	if (!root) return NULL;

	if (less(val, root->val))
		root->left = __node_clear__(root->left, val);

	if (less(root->val, val))
		root->right = __node_clear__(root->right, val);

	else
	{
		if (!root->left && !root->right)
		{
			delete_node(root);
			return NULL;
		}
		else if (!root->left && root->right)
		{
			swap_val(root, root->right);
			root->right = __node_clear__(root->right, val);
		}
		else if (!root->right && root->left)
		{
			swap_val(root, root->left);
			root->left = __node_clear__(root->left, val);
		}
		else if (root->left && root->right)
		{
			tree_node *predeccessor = __find_max__(root->left);
			swap_val(predeccessor, root);
			root->left = __node_clear__(root->left, val);
		}
	}
	return root;
}

void node_clear(t_tree *tree,   t_treeval val)
{
	if (!tree) return;

	tree->root = __node_clear__(tree->root, val);

}
