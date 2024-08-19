/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:17:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	left_rotate(t_tree *tree, t_tree_node *x)
{
	t_tree_node	*y;

	y = x->right;
	x->right = y->left;
	if (y->left != tree->nil)
		y->left->p = x;
	y->p = x->p;
	if (x->p == tree->nil)
		tree->root = y;
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;
	y->left = x;
	x->p = y;
}

void	right_rotate(t_tree *tree, t_tree_node *x)
{
	t_tree_node	*y;

	y = x->left;
	x->left = y->right;
	if (y->right != tree->nil)
		y->right->p = x;
	y->p = x->p;
	if (x->p == tree->nil)
		tree->root = y;
	else if (x == x->p->right)
		x->p->right = y;
	else
		x->p->left = y;
	y->right = x;
	x->p = y;
}
