/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:09:06 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 22:09:07 by aamirkha         ###   ########.fr       */
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
