/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:09:47 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 22:09:48 by aamirkha         ###   ########.fr       */
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
