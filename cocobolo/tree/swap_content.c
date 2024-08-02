/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:32:24 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 15:38:48 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void swap_content(tree_node *lhv, tree_node *rhv)
{
	if (!rhv || !lhv) return;

	tree_node *tmp;

	tmp = make_tree_node(NULL, NULL);
	treeval_move(tmp, rhv);
	treeval_move(rhv, lhv);
	treeval_move(lhv, tmp);

	delete_node(tmp);
}

