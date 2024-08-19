/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postorder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:06:21 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	__postorder__(t_tree *tree, t_tree_node *node, t_fptr foo)
{
	if (node == tree->nil || foo == NULL)
		return ;
	__postorder__(tree, node->left, foo);
	__postorder__(tree, node->right, foo);
	foo(node);
}

void	postorder(t_tree *tree, t_fptr foo)
{
	__postorder__(tree, tree->root, foo);
}
