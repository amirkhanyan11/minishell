/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:58:02 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 20:50:25 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	__insert_node__(tree_node **root, int val)
{
	if (NULL == *root)
		*root = make_tree_node(val);
	else if (less(val, (*root)->val))
		__insert_node__(&((*root)->left), val);
	else if (greater(val, (*root)->val))
		__insert_node__(&((*root)->right), val);
}

void	insert_node(t_tree *tree, int val)
{
	__insert_node__(&tree->root, val);
}
