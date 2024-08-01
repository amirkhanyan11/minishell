/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:45:00 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 20:48:38 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void __preorder__(tree_node *node, fptr foo)
{
	if(node == NULL || foo == NULL)
		return ;
	foo(node);
	__preorder__(node->left, foo);
	__preorder__(node->right, foo);
}

void preorder(t_tree *tree, fptr foo)
{
	__preorder__(tree->root, foo);
}
