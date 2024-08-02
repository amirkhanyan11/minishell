/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:50:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 18:20:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void __print_key__(tree_node *root)
{
	printf("%s = %s\n", root->key, root->val);
}

void print_tree_preorder(t_tree *tree)
{
	preorder(tree, __print_key__);
}

void print_tree_inorder(t_tree *tree)
{
	inorder(tree, __print_key__);
}

void print_tree_postorder(t_tree *tree)
{
	postorder(tree, __print_key__);
}

void print_tree_inorder_custom(t_tree *tree, fptr foo)
{
	inorder(tree, foo);
}

void print_tree_preorder_custom(t_tree *tree, fptr foo)
{
	preorder(tree, foo);
}

void print_tree_postorder_custom(t_tree *tree, fptr foo)
{
	postorder(tree, foo);
}
