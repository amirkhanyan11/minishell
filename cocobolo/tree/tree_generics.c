/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_generics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:34:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 15:44:56 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <cocobolo.h>

bool less(t_treeval a, t_treeval b)
{
	return (__strcmp(a, b) < 0);
}

void __treeval_copy__(t_treeval *lhv, t_treeval *rhv)
{
	if (*lhv == *rhv) return;

	__delete_string(lhv);
	*lhv = __strdup(*rhv);
}

void treeval_copy(tree_node *lhv, tree_node *rhv)
{
	__treeval_copy__(&lhv->key, &rhv->key);
	__treeval_copy__(&lhv->val, &rhv->val);
}

void __treeval_move__(t_treeval *lhv, t_treeval *rhv)
{
	if (*lhv == *rhv) return;

	__delete_string(lhv);
	*lhv = *rhv;
	*rhv = NULL;
}

void treeval_move(tree_node *lhv, tree_node *rhv)
{
	__treeval_move__(&lhv->key, &rhv->key);
	__treeval_move__(&lhv->val, &rhv->val);
}
