/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:45:00 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 20:14:46 by marikhac         ###   ########.fr       */
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
