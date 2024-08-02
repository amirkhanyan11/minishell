/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:32:24 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 14:42:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void swap_val(tree_node *lhv, tree_node *rhv)
{
	if (!rhv || !lhv) return;

	t_treeval tmp;
	treeval_move(&tmp, &rhv->val);
	treeval_move(&rhv->val, &lhv->val);
	treeval_move(&lhv->val, &tmp);
}
