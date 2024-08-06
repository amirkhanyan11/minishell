/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:22:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// move to separate dir
t_matrix  make_matrix_from_string(char *s, char *set)
{
	return __split(s, set);
}

t_matrix  make_matrix_copy(t_matrix other)
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

t_matrix  make_matrix_from_list(t_list *list)
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

static void __matrix_insert__(t_matrix arr, char *val, size_t *i)
{

	if (arr == NULL) return;

	arr[*i] = __strdup(val);

	++(*i);
}


static void   __make_matrix_from_tree__(t_matrix arr, tree_node *root, size_t *i)
{
	if (!root) return;

	__make_matrix_from_tree__(arr, root->left, i);

	string val = __make_string(root->key, "=", root->val);

	__matrix_insert__(arr, val, i);

	__make_matrix_from_tree__(arr, root->right, i);
}


t_matrix   make_matrix_from_tree(t_tree *tree)
{
	if (tree_empty(tree)) return NULL;

	size_t size = tree_size(tree);

	t_matrix arr = __malloc(sizeof(char *) * (size + 1));

	arr[size] = NULL;

	size_t i = 0;

	__make_matrix_from_tree__(arr, tree->root, &i);

	return arr;
}
