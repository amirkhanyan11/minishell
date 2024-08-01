/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postorder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:45:00 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 18:08:34 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void __postorder__(tree_node *node, fptr foo)
{
	if(node == NULL || foo == NULL)
		return ;
	__postorder__(node->left, foo);
	__postorder__(node->right, foo);
	foo(node);
}

void postorder(t_tree *tree, fptr foo)
{
	__postorder__(tree->root, foo);
}
