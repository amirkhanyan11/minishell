/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:22:41 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/09 21:28:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static size_t __tree_height__(t_tree *tree, tree_node *curr)
{
	if (curr == tree->NIL) return 0;

	size_t l = __tree_height__(tree, curr->left);
	size_t r = __tree_height__(tree, curr->right);

	return 1 + ((l > r) ? l : r);
}


size_t tree_height(t_tree *tree)
{
	if (!tree) return 0;

	return __tree_height__(tree, tree->root);
}
