/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:35:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 19:37:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static size_t __tree_size__(tree_node *root)
{
	if (!root) return 0;

	return 1 + __tree_size__(root->left) + __tree_size__(root->right);
}

size_t tree_size(t_tree *tree)
{
	if (tree_empty(tree)) return 0;

	return __tree_size__(tree->root);
}
