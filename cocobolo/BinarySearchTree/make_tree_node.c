/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:09:23 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 22:09:23 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"

tree_node *make_tree_node(const int val)
{
	tree_node *new_node;
	new_node = malloc(sizeof(tree_node));
	new_node->val = val;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
