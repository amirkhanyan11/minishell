/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:22:24 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 20:14:46 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

tree_node *__find_max__(tree_node *root)
{
	return (root == NULL || !root->right) ? root : __find_max__(root->right);
}

tree_node *find_max(t_tree *tree)
{
	if (!tree) return NULL;

	return __find_max__(tree->root);
}
