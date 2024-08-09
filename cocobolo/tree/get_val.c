/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:02:21 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/09 21:26:08 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_treeval	get_val(t_tree *tree, t_treeval key)
{
	tree_node *node = tree_find(tree, key);

	if (node == tree->NIL) return NULL;

	return node->val;
}
