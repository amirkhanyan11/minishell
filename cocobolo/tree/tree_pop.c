#include "tree.h"

static tree_node *__tree_pop__(tree_node *root, t_treeval key, t_cmp less)
{
	if (!root) return NULL;

	if (less(key, root->key))
		root->left = __tree_pop__(root->left, key, less);

	if (less(root->key, key))
		root->right = __tree_pop__(root->right, key, less);

	else if (!less(key, root->key) && !less(root->key, key))
	{
		if (!root->left && !root->right)
		{
			delete_node(root);
			return NULL;
		}
		else if (!root->left && root->right)
		{
			swap_content(root, root->right);
			root->right = __tree_pop__(root->right, key, less);
		}
		else if (!root->right && root->left)
		{
			swap_content(root, root->left);
			root->left = __tree_pop__(root->left, key, less);
		}
		else if (root->left && root->right)
		{
			tree_node *predeccessor = __find_max__(root->left);
			swap_content(predeccessor, root);
			root->left = __tree_pop__(root->left, key, less);
		}
	}
	return root;
}

void tree_pop(t_tree *tree,   t_treeval key)
{
	if (!tree) return;

	tree->root = __tree_pop__(tree->root, key, tree->less);

}
