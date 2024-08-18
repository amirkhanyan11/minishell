/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:22:41 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:59:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static size_t	__tree_height__(t_tree *tree, tree_node *curr)
{
	size_t	l;
	size_t	r;

	if (curr == tree->NIL)
		return (0);
	l = __tree_height__(tree, curr->left);
	r = __tree_height__(tree, curr->right);
	return (1 + ((l > r) ? l : r));
}

size_t	tree_height(t_tree *tree)
{
	if (!tree)
		return (0);
	return (__tree_height__(tree, tree->root));
}
