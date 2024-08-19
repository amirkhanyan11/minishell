/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:06:12 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree_node	*__find_min__(t_tree *tree, t_tree_node *root)
{
	if (root == tree->nil || root->left == tree->nil)
		return (root);
	else
		return (__find_min__(tree, root->left));
}

t_tree_node	*find_min(t_tree *tree)
{
	if (!tree)
		return (NULL);
	return (__find_min__(tree, tree->root));
}
