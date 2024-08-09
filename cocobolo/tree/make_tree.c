/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:26:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/09 21:35:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <cocobolo.h>
#include "minishell.h" // for matrix. Better change

static void __make_tree_copy__(t_tree *tree, t_tree *other, tree_node *root);

t_tree *make_tree(t_cmp less)
{
	t_tree *new_tree;

	if (less == NULL) less = string_less;

	new_tree = __malloc(sizeof(t_tree));
	new_tree->less = less;
	new_tree->NIL = make_tree_node(NULL, NULL, NULL, BLACK);
	new_tree->root = new_tree->NIL;
	return new_tree;
}

t_tree *make_tree_copy(t_tree *other)
{
	if (!other) return NULL;

	t_tree *tree = make_tree(other->less);

	__make_tree_copy__(tree, other, other->root);

	return tree;
}

static void __make_tree_copy__(t_tree *tree, t_tree *other, tree_node *root)
{
	if (!tree || root == other->NIL) return;

	tree_update(tree, root->key, root->val);
	__make_tree_copy__(tree, other, root->left);
	__make_tree_copy__(tree, other, root->right);
}

t_tree *make_tree_from_matrix(t_treeval *arr, t_cmp less)
{
	if (less == NULL) less = string_less;

	t_tree *tree = make_tree(less);

	if (NULL == arr) return tree;

	size_t i = 0;

	while (arr[i])
	{
		scoped_matrix pair = __split(arr[i], "=");

		if (__matrix_size(pair) >= 1)
		{
			char *val = pair[pair_val];
			if (val == NULL) val = "";
			tree_update(tree, pair[pair_key], val);
		}
		i++;
	}

	return tree;
}
