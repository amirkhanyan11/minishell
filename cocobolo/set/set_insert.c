/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:52:21 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 22:44:44 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void	set_insert(t_set *set, char *val)
{
	if (!set || !val)
		return ;
	tree_update(set->tree, val, NULL);
}
