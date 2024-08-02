/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 19:49:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// move to separate dir
t_matrix __result_use_check  make_matrix_from_string(char *s, char *set)
{
	return __split(s, set);
}

t_matrix  __result_use_check make_matrix_copy(t_matrix other)
{
	if (!other) return NULL;

	size_t i = 0;
	while (other[i]) i++;

	t_matrix res = malloc(i + 1);
	res[i] = NULL;

	i = 0;
	while(other[i])
	{
		res[i] = __strdup(other[i]);
		i++;
	}
	return res;
}

t_matrix  __result_use_check make_matrix_from_list(t_list *list)
{
	if (!list) return NULL;

	size_t lstsize = size(list);

	t_matrix arr = __malloc(sizeof(char *) * (lstsize + 1));

	arr[lstsize] = NULL;

	t_node *node = list->head;
	size_t i = 0;
	while (node)
	{
		arr[i] = __strdup(node->val);
		node = node->next;
		i++;
	}

	return arr;
}

static void __matrix_insert__(t_matrix arr, char *val)
{
	static size_t i = 0;

	arr[i] = __strdup(val);

	i++;
}


static void   __make_matrix_from_tree__(t_matrix arr, tree_node *root)
{
	if (!root) return;

	__make_matrix_from_tree__(arr, root->left);

	string val = __strappend(__make_string_empty(), root->key, "=", root->val);

	__matrix_insert__(arr, val);

	__make_matrix_from_tree__(arr, root->right);
}


t_matrix  	__result_use_check make_matrix_from_tree(t_tree *tree)
{
	if (tree_empty(tree)) return NULL;

	t_matrix arr = __malloc(sizeof(char *) * (tree_size(tree) + 1));

	__make_matrix_from_tree__(arr, tree->root);

	return arr;
}
