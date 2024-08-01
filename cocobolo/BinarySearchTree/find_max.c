/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

tree_node *__find_max__(tree_node *root)
{
	return (root == NULL || !root->right) ? root : __find_max__(root->right);
}

tree_node *find_max(t_tree *tree)
{
	if (!tree) return NULL;

	return __find_max__(tree->root);
}
