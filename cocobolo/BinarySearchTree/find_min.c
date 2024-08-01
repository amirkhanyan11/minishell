/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:28:32 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 20:14:46 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

tree_node *__find_min__(tree_node *root)
{
	return (root == NULL || !root->left) ? root : __find_min__(root->left);
}

tree_node *find_min(t_tree *tree)
{
	if (!tree) return NULL;

	return __find_min__(tree->root);
}
