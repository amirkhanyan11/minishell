/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postorder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:09:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 22:09:43 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

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
