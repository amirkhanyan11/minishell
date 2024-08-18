/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:35:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 22:00:11 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static size_t	__tree_size__(t_tree *tree, tree_node *root)
{
	if (root == tree->NIL)
		return (0);
	return (1 + __tree_size__(tree, root->left) + __tree_size__(tree,
			root->right));
}

size_t	tree_size(t_tree *tree)
{
	if (tree_empty(tree))
		return (0);
	return (__tree_size__(tree, tree->root));
}
