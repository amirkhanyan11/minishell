/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:06:42 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	__preorder__(t_tree *tree, t_tree_node *node, t_fptr foo)
{
	if (node == tree->nil || foo == NULL)
		return ;
	foo(node);
	__preorder__(tree, node->left, foo);
	__preorder__(tree, node->right, foo);
}

void	preorder(t_tree *tree, t_fptr foo)
{
	__preorder__(tree, tree->root, foo);
}
