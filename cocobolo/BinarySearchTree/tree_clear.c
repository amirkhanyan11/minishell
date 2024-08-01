/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:10:09 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 22:10:11 by aamirkha         ###   ########.fr       */
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
