/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:39:01 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 18:13:46 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

tree_node *__search__(tree_node *root, int val)
{
 	if (NULL == root || val == root->val)
		return root;
	if (val > root->val)
		return(__search__(root->right, val));
	else
		return(__search__(root->left, val));
}

tree_node *search(t_tree *tree, int val)
{
	return(__search__(tree->root, val));
}
