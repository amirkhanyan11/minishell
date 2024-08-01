/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:10:01 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 22:10:02 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tree.h"


void swap_val(tree_node *lhv, tree_node *rhv)
{
	if (!rhv || !lhv) return;

	int tmp = rhv->val;
	rhv->val = lhv->val;
	lhv->val = tmp;
}
