/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:09:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 22:09:53 by aamirkha         ###   ########.fr       */
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
