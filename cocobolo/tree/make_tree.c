/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:26:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:06:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" // for matrix. Better change
#include "tree.h"
#include <cocobolo.h>

static void	__make_tree_copy__(t_tree *tree, t_tree *other, t_tree_node *root);

t_tree	*make_tree(t_cmp less)
{
	t_tree	*new_tree;

	if (less == NULL)
		less = string_less;
	new_tree = __malloc(sizeof(t_tree));
	new_tree->less = less;
	new_tree->nil = make_tree_node(NULL, NULL, NULL, BLACK);
	new_tree->root = new_tree->nil;
	return (new_tree);
}

t_tree	*make_tree_copy(t_tree *other)
{
	t_tree	*tree;

	if (!other)
		return (NULL);
	tree = make_tree(other->less);
	__make_tree_copy__(tree, other, other->root);
	return (tree);
}

static void	__make_tree_copy__(t_tree *tree, t_tree *other, t_tree_node *root)
{
	if (!tree || root == other->nil)
		return ;
	tree_update(tree, root->key, root->val);
	__make_tree_copy__(tree, other, root->left);
	__make_tree_copy__(tree, other, root->right);
}

t_tree	*make_tree_from_matrix(t_treeval *arr, t_cmp less)
{
	t_tree	*tree;
	size_t	i;
	t_list	*tokens;
	char	*val;

	if (less == NULL)
		less = string_less;
	tree = make_tree(less);
	if (NULL == arr)
		return (tree);
	i = 0;
	while (arr[i])
	{
		tokens = make_list_from_string(arr[i], "=", all);
		val = __make_string_from_list(front(tokens)->next->next, back(tokens));
		tree_update(tree, front(tokens)->val, val);
		list_clear(&tokens);
		__delete_string(&val);
		i++;
	}
	return (tree);
}
