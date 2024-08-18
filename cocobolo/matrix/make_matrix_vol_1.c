/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:07:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

t_matrix	make_matrix_from_string(char *s, char *set)
{
	return (__split(s, set));
}

t_matrix	make_matrix_copy(t_matrix other)
{
	size_t		i;
	t_matrix	res;

	if (!other)
		return (NULL);
	i = 0;
	while (other[i])
		i++;
	res = malloc(i + 1);
	res[i] = NULL;
	i = 0;
	while (other[i])
	{
		res[i] = __strdup(other[i]);
		i++;
	}
	return (res);
}

t_matrix	make_matrix_from_list(t_list *list)
{
	size_t		lstsize;
	t_matrix	arr;
	t_node		*node;
	size_t		i;

	if (!list)
		return (NULL);
	lstsize = size(list);
	arr = __malloc(sizeof(char *) * (lstsize + 1));
	arr[lstsize] = NULL;
	node = front(list);
	i = 0;
	while (node)
	{
		arr[i] = __strdup(node->val);
		node = node->next;
		i++;
	}
	return (arr);
}

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
