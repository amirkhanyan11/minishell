/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:26:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 17:01:28 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <cocobolo.h>

static void __make_tree_copy__(t_tree *tree, tree_node *root);

t_tree *make_tree()
{
	t_tree *new_tree;

	new_tree = malloc(sizeof(t_tree));
	new_tree->root = NULL;
	return new_tree;
}


t_tree *make_tree_copy(t_tree *other)
{
	t_tree *tree = make_tree();

	__make_tree_copy__(tree, other->root);

	return tree;
}

t_tree *make_tree_from_matrix(t_treeval *arr)
{
	if (NULL == arr) return make_tree();

	size_t i = 0;
	t_tree *new_tree = make_tree();

	while (arr[i])
	{
		a_matrix pair = __split(arr[i], "=");
		char *val = pair[pair_val];

		if (__matrix_size(pair) >= 1)
		{
			if (val == NULL)
			{
				val = "";
			}
			tree_update(new_tree, pair[pair_key], val);
		}
		i++;
	}
	return new_tree;
}

static void __make_tree_copy__(t_tree *tree, tree_node *root)
{
	if (!tree || !root) return;

	tree_update(tree, root->key, root->val);
	__make_tree_copy__(tree, root->left);
	__make_tree_copy__(tree, root->right);
}
