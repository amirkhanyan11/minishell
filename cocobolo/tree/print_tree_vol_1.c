/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree_vol_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:50:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:02:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	__print_key__(t_tree_node *root)
{
	printf("%s = %s\n", root->key, root->val);
}

void	print_tree_preorder(t_tree *tree)
{
	preorder(tree, __print_key__);
}

void	print_tree_inorder(t_tree *tree)
{
	inorder(tree, __print_key__);
}
