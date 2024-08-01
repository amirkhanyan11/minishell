/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:49:52 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 20:14:46 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

tree_node *make_node(const int val)
{
	tree_node *new_node;
	new_node = malloc(sizeof(tree_node));
	new_node->val = val;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
