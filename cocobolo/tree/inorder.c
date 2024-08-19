/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:24:00 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	__inorder__(t_tree *tree, t_tree_node *node, t_fptr foo)
{
	if (node == tree->nil || foo == NULL)
		return ;
	__inorder__(tree, node->left, foo);
	foo(node);
	__inorder__(tree, node->right, foo);
}

void	inorder(t_tree *tree, t_fptr foo)
{
	__inorder__(tree, tree->root, foo);
}
