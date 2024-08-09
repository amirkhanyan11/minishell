/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:42:59 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/09 21:06:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void transplant(t_tree *tree, tree_node *u, tree_node *v)
{
	if (!tree) return;

	if (u->p == tree->NIL) tree->root = v;

	else if (u == u->p->left) u->p->left = v;

	else u->p->right = v;

	v->p = u->p;
}

static void _delete_fixup(t_tree *tree, tree_node *x)
{
	while (x != tree->root && x->color == BLACK)
	{
		tree_node *w = tree->NIL;
		if (x == x->p->left)
		{
			w = x->p->right;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->p->color = RED;
				left_rotate(tree, x->p);
				w = x->p->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->p;
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(tree, w);
					w = x->p->right;
				}

				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				left_rotate(tree, x->p);
				x = tree->root;
			}
		}
		else
		{
			w = x->p->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->p->color = RED;
				right_rotate(tree, x->p);
				w = x->p->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK)
			{
				w->color = RED;
				x = x->p;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					left_rotate(tree, w);
					w = x->p->left;
				}

				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				right_rotate(tree, x->p);
				x = tree->root;
			}
		}
	}
	x->color = BLACK;
}

static void _delete(t_tree *tree, tree_node *z)
{
	tree_node *x = tree->NIL;
	tree_node *y = z;
	t_color y_orig_color = y->color;

	if (z->left == tree->NIL)
	{
		x = z->right;
		transplant(tree, z, z->right);
	}
	else if (z->right == tree->NIL)
	{
		x = z->left;
		transplant(tree, z, z->left);
	}
	else
	{
		y = __find_min__(tree, z->right);
		y_orig_color = y->color;
		x = y->right;

		if (y->p == z)
			x->p = y;

		else
		{
			transplant(tree, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}

		transplant(tree, z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}

	delete_node(z);
	z = NULL;

	if (y_orig_color == BLACK)
		_delete_fixup(tree, x);

}


void tree_remove(t_tree *tree, t_treeval key)
{
	if (!tree) return;

	tree_node *z = tree_find(tree, key);

	if (z != tree->NIL) _delete(tree, z);

}
