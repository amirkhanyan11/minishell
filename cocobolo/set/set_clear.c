/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:46:10 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 21:19:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void set_clear(t_set **setptr)
{
	if(*setptr == NULL)
		return ;
	t_set *set = *setptr;
	tree_clear(&set->tree);
	*setptr = NULL;
}
