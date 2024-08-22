/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:53:47 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 22:44:46 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void	set_remove(t_set *set, char *val)
{
	if (!set || !val)
		return ;
	tree_remove(set->tree, val);
}
