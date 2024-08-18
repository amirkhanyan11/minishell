/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix_vol_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:26:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:27:21 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

static void	__matrix_insert__(t_matrix arr, char *val, size_t *i)
{
	if (arr == NULL)
		return ;
	arr[*i] = __strdup(val);
	++(*i);
}

static void	__make_matrix_from_tree__(t_matrix arr, t_tree *tree,
		tree_node *curr, size_t *i)
{
	scoped_string	val;

	val = NULL;
	if (curr == tree->NIL)
		return ;
	__make_matrix_from_tree__(arr, tree, curr->left, i);
	val = __make_string(curr->key, "=", curr->val);
	__matrix_insert__(arr, val, i);
	__make_matrix_from_tree__(arr, tree, curr->right, i);
}

t_matrix	make_matrix_from_tree(t_tree *tree)
{
	size_t		size;
	t_matrix	arr;
	size_t		i;

	if (tree_empty(tree))
		return (NULL);
	size = tree_size(tree);
	arr = __malloc(sizeof(char *) * (size + 1));
	arr[size] = NULL;
	i = 0;
	__make_matrix_from_tree__(arr, tree, tree->root, &i);
	return (arr);
}
