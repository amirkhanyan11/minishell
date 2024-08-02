/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:24:00 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 16:24:03 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void __inorder__(tree_node *node, fptr foo)
{
	if(node == NULL || foo == NULL)
		return ;
	__inorder__(node->left, foo);
	foo(node);
	__inorder__(node->right, foo);
}

void inorder(t_tree *tree, fptr foo)
{
	__inorder__(tree->root, foo);
}
