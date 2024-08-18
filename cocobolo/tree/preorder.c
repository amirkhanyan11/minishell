/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:06:42 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 22:06:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	__preorder__(t_tree *tree, tree_node *node, fptr foo)
{
	if (node == tree->NIL || foo == NULL)
		return ;
	foo(node);
	__preorder__(tree, node->left, foo);
	__preorder__(tree, node->right, foo);
}

void	preorder(t_tree *tree, fptr foo)
{
	__preorder__(tree, tree->root, foo);
}
