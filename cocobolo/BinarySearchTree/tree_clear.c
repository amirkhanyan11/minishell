/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:21:41 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 20:48:38 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void delete_node(tree_node *node)
{
	node->left = NULL;
	node->right = NULL;
	free(node);
}

void tree_clear(t_tree **treeptr)
{
	if (!treeptr || !(*treeptr)) return;

	t_tree *tree = *treeptr;
	postorder(tree, delete_node);
	tree->root = NULL;
	free(tree);
	*treeptr = NULL;

}
