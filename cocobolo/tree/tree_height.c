/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:22:41 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static size_t	__tree_height__(t_tree *tree, t_tree_node *curr)
{
	size_t	l;
	size_t	r;
	size_t	x;

	if (curr == tree->nil)
		return (0);
	l = __tree_height__(tree, curr->left);
	r = __tree_height__(tree, curr->right);
	x = 0;
	if (l > r)
		x = l;
	else
		x = r;
	return (1 + x);
}

size_t	tree_height(t_tree *tree)
{
	if (!tree)
		return (0);
	return (__tree_height__(tree, tree->root));
}
