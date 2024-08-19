/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:06:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <cocobolo.h>

void	delete_node(t_tree_node *node)
{
	__delete_string(&node->key);
	__delete_string(&node->val);
	node->left = NULL;
	node->right = NULL;
	free(node);
}

void	tree_clear(t_tree **treeptr)
{
	t_tree	*tree;

	if (!treeptr || !(*treeptr))
		return ;
	tree = *treeptr;
	postorder(tree, delete_node);
	delete_node(tree->nil);
	tree->nil = NULL;
	tree->root = NULL;
	free(tree);
	*treeptr = NULL;
}
