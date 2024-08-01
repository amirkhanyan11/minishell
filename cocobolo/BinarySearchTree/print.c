/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:03:17 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 20:48:38 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static void __print_val__(tree_node *root)
{
	printf("%d ", root->val);
}

void print_preorder(t_tree *tree)
{
	preorder(tree, __print_val__);
	printf("\n");
}

void print_inorder(t_tree *tree)
{
	inorder(tree, __print_val__);
	printf("\n");
}

void print_postorder(t_tree *tree)
{
	postorder(tree, __print_val__);
	printf("\n");
}
