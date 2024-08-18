/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_remove_vol_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:26:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 22:47:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void	left_case_4(t_tree *tree, tree_node **x)
{
	tree_node	*w;

	w = (*x)->p->right;
	if (w->right->color == BLACK)
	{
		w->left->color = BLACK;
		w->color = RED;
		right_rotate(tree, w);
		w = (*x)->p->right;
	}
	w->color = (*x)->p->color;
	(*x)->p->color = BLACK;
	w->right->color = BLACK;
	left_rotate(tree, (*x)->p);
	(*x) = tree->root;
}

static void	right_case_4(t_tree *tree, tree_node **x)
{
	tree_node	*w;

	w = (*x)->p->left;
	if (w->left->color == BLACK)
	{
		w->right->color = BLACK;
		w->color = RED;
		left_rotate(tree, w);
		w = (*x)->p->left;
	}
	w->color = (*x)->p->color;
	(*x)->p->color = BLACK;
	w->left->color = BLACK;
	right_rotate(tree, (*x)->p);
	(*x) = tree->root;
}

static void	left_case(t_tree *tree, tree_node **x)
{
	tree_node	*w;

	w = (*x)->p->right;
	if (w->color == RED)
	{
		w->color = BLACK;
		(*x)->p->color = RED;
		left_rotate(tree, (*x)->p);
		w = (*x)->p->right;
	}
	if (w->left->color == BLACK && w->right->color == BLACK)
	{
		w->color = RED;
		(*x) = (*x)->p;
	}
	else
		left_case_4(tree, x);
}

static void	right_case(t_tree *tree, tree_node **x)
{
	tree_node	*w;

	w = (*x)->p->left;
	if (w->color == RED)
	{
		w->color = BLACK;
		(*x)->p->color = RED;
		right_rotate(tree, (*x)->p);
		w = (*x)->p->left;
	}
	if (w->right->color == BLACK && w->left->color == BLACK)
	{
		w->color = RED;
		(*x) = (*x)->p;
	}
	else
		right_case_4(tree, x);
}

void	_delete_fixup(t_tree *tree, tree_node *x)
{
	while (x != tree->root && x->color == BLACK)
	{
		if (x == x->p->left)
		{
			left_case(tree, &x);
		}
		else
		{
			right_case(tree, &x);
		}
	}
	x->color = BLACK;
}
