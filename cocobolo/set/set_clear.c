/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:46:10 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/12 19:44:58 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void	set_clear(t_set **setptr)
{
	t_set	*set;

	if (*setptr == NULL)
		return ;
	set = *setptr;
	tree_clear(&set->tree);
	free(set);
	*setptr = NULL;
}
