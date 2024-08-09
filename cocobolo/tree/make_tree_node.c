/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:22:16 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/09 21:03:01 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"
#include <cocobolo.h>

tree_node *make_tree_node(t_treeval key, t_treeval val, tree_node *NIL, t_color color)
{
	tree_node *new_node;
	new_node = __malloc(sizeof(tree_node));
	new_node->key = NULL;
	new_node->val = NULL;
	__treeval_copy__(&new_node->key, &key);
	__treeval_copy__(&new_node->val, &val);
	new_node->left = NIL;
	new_node->right = NIL;
	new_node->p = NIL;
	new_node->color = color;
	return new_node;
}
