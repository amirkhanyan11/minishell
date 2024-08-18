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

tree_node	*__find_max__(t_tree *tree, tree_node *root)
{
	if (root == tree->NIL || root->right == tree->NIL)
		return (root);
	else
		return (__find_max__(tree, root->right));
}

tree_node	*find_max(t_tree *tree)
{
	if (!tree)
		return (NULL);
	return (__find_max__(tree, tree->root));
}
