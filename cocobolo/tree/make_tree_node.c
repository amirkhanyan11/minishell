/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:16 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/02 15:41:30 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"

tree_node *make_tree_node(t_treeval key, t_treeval val)
{
	tree_node *new_node;
	new_node = malloc(sizeof(tree_node));
	new_node->key = NULL;
	new_node->val = NULL;
	__treeval_copy__(&new_node->key, &key);
	__treeval_copy__(&new_node->val, &val);
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
