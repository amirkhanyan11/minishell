/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:06:06 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree_node	*__find_max__(t_tree *tree, t_tree_node *root)
{
	if (root == tree->nil || root->right == tree->nil)
		return (root);
	else
		return (__find_max__(tree, root->right));
}

t_tree_node	*find_max(t_tree *tree)
{
	if (!tree)
		return (NULL);
	return (__find_max__(tree, tree->root));
}
