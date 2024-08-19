/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree_vol_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:52:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 16:53:00 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	print_tree_postorder(t_tree *tree)
{
	postorder(tree, __print_key__);
}

void	print_tree_inorder_custom(t_tree *tree, fptr foo)
{
	inorder(tree, foo);
}

void	print_tree_preorder_custom(t_tree *tree, fptr foo)
{
	preorder(tree, foo);
}

void	print_tree_postorder_custom(t_tree *tree, fptr foo)
{
	postorder(tree, foo);
}
