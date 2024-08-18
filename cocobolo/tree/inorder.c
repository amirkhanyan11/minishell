/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:24:00 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:58:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	__inorder__(t_tree *tree, tree_node *node, fptr foo)
{
	if (node == tree->NIL || foo == NULL)
		return ;
	__inorder__(tree, node->left, foo);
	foo(node);
	__inorder__(tree, node->right, foo);
}

void	inorder(t_tree *tree, fptr foo)
{
	__inorder__(tree, tree->root, foo);
}
