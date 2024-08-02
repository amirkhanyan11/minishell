/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:26:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 20:40:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <cocobolo.h>
#include "minishell.h" // for matrix. Better change

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

static tree_node *__make_tree_from_matrix__(t_matrix arr, int low, int high)
{
	if (low > high) return NULL;

	int mid = low + (high - low) / 2;

	tree_node *root = NULL;

	a_matrix pair = __split(arr[mid], "=");

	if (__matrix_size(pair) >= 1)
	{
		char *val = pair[pair_val];

		if (val == NULL) val = "";

		root = make_tree_node(pair[pair_key], val);
		root->left = __make_tree_from_matrix__(arr, low, mid - 1);
		root->right = __make_tree_from_matrix__(arr, mid + 1, high);
	}
	return root;
}

t_tree *make_tree_from_matrix(t_treeval *arr)
{
	if (NULL == arr) return make_tree();

	t_tree *tree = make_tree();

	matrix_sort(arr, NULL);

	tree->root = __make_tree_from_matrix__(arr, 0, __matrix_size(arr) - 1);

	return tree;
}

static void __make_tree_copy__(t_tree *tree, tree_node *root)
{
	if (!tree || !root) return;

	tree_update(tree, root->key, root->val);
	__make_tree_copy__(tree, root->left);
	__make_tree_copy__(tree, root->right);
}