/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:16 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/19 17:06:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <cocobolo.h>

t_tree_node	*make_tree_node(t_treeval key, t_treeval val, t_tree_node *nil,
		t_color color)
{
	t_tree_node	*new_node;

	new_node = __malloc(sizeof(t_tree_node));
	new_node->key = NULL;
	new_node->val = NULL;
	__treeval_copy__(&new_node->key, &key);
	__treeval_copy__(&new_node->val, &val);
	new_node->left = nil;
	new_node->right = nil;
	new_node->p = nil;
	new_node->color = color;
	return (new_node);
}
