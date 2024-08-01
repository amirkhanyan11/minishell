/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:17:41 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/01 17:18:41 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void swap_val(tree_node *lhv, tree_node *rhv)
{
	if (!rhv || !lhv) return;
	
	int tmp = rhv->val;
	rhv->val = lhv->val;
	lhv->val = tmp;
}
