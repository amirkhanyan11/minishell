/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_generics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:34:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:02:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <cocobolo.h>

void	__treeval_copy__(t_treeval *lhv, t_treeval *rhv)
{
	if (*lhv == *rhv)
		return ;
	__delete_string(lhv);
	*lhv = __strdup(*rhv);
}

void	treeval_copy(t_tree_node *lhv, t_tree_node *rhv)
{
	__treeval_copy__(&lhv->key, &rhv->key);
	__treeval_copy__(&lhv->val, &rhv->val);
}

void	__treeval_move__(t_treeval *lhv, t_treeval *rhv)
{
	if (*lhv == *rhv)
		return ;
	__delete_string(lhv);
	*lhv = *rhv;
	*rhv = NULL;
}

void	treeval_move(t_tree_node *lhv, t_tree_node *rhv)
{
	__treeval_move__(&lhv->key, &rhv->key);
	__treeval_move__(&lhv->val, &rhv->val);
}
