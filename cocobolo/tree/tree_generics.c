/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_generics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:34:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 14:37:13 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <cocobolo.h>

bool less(t_treeval a, t_treeval b)
{
	return (__strcmp(a, b) < 0);
}

void treeval_copy(t_treeval *lhv, t_treeval *rhv)
{
	if (*lhv == *rhv) return;

	__delete_string(lhv);
	*lhv = __strdup(*rhv);
}

void treeval_move(t_treeval *lhv, t_treeval *rhv)
{
	if (*lhv == *rhv) return;

	__delete_string(lhv);
	*lhv = *rhv;
	*rhv = NULL;
}
