/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:56:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 22:44:41 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

size_t	set_count(t_set *set, char *val)
{
	if (!set || !val || tree_find(set->tree, val) == set->tree->nil)
		return (0);
	return (1);
}
