/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:46:10 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 20:51:32 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void set_clear(t_set **setptr)
{
	if(*setptr == NULL)
		return ;
	t_set *set = *setptr;
	tree_clear(set->tree);
	*setptr = NULL;
}
