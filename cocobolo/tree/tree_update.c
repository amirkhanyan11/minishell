/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:07:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 22:07:23 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"

// static void	__insert_node__(tree_node **root, t_treeval key, t_treeval val, t_cmp less)
// {
// 	if (NULL == *root)
// 		*root = make_tree_node(key, val);
// 	else if (less(key, (*root)->key))
// 		__insert_node__(&((*root)->left), key, val, less);
// 	else if (less((*root)->key, key))
// 		__insert_node__(&((*root)->right), key, val, less);
// }


// void	tree_update(t_tree *tree, t_treeval key, t_treeval val)
// {
// 	if (!tree) return ;
// 	tree_pop(tree, key);
// 	__insert_node__(&tree->root, key, val, tree->less);
// }

static void	_insert_fixup(t_tree *tree, tree_node *z)
{
	while (z->p->color == RED)
	{
		if (z->p == z->p->p->left)
		{
			tree_node *y = z->p->p->right;

			if (y->color == RED)
			{
				y->color = BLACK;
				z->p->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else
			{
				if (z == z->p->right)
				{
					z = z->p;
					left_rotate(tree, z);
				}
				z->p->color = BLACK;
                z->p->p->color = RED;
                right_rotate(tree, z->p->p);
			}
		}
		else
		{
			tree_node *y = z->p->p->left;

			if (y->color == RED)
			{
				y->color = BLACK;
				z->p->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else
			{
				if (z == z->p->left)
				{
					z = z->p;
					right_rotate(tree, z);
				}
				z->p->color = BLACK;
                z->p->p->color = RED;
                left_rotate(tree, z->p->p);
			}
		}
	}
	tree->root->color = BLACK;
}


static void	_insert(t_tree *tree, tree_node *z)
{
	tree_node *y = tree->NIL;
	tree_node *x = tree->root;

	while (x != tree->NIL)
	{
		y = x;

		if (tree->less(z->key, x->key)) x = x->left;

		else x = x->right;
	}

	z->p = y;

	if (y == tree->NIL) tree->root = z;

	else if (tree->less(z->key, y->key)) y->left = z;

	else y->right = z;

	_insert_fixup(tree, z);
}


void	tree_update(t_tree *tree, t_treeval key, t_treeval val)
{
	if (!tree) return ;
	tree_remove(tree, key);
	_insert(tree, make_tree_node(key, val, tree->NIL, RED));
}
