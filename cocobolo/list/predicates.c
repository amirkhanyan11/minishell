/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:30:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/10 15:27:28 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

bool	list_value_same(const char *lhv, const char *rhv)
{
	if (!lhv || !rhv)
		return (!lhv && !rhv);
	return (__strcmp(lhv, rhv) == 0);
}

bool	list_value_contains(t_list_value lhv, t_list_value rhv)
{
	if (!lhv || !rhv)
		return (!lhv && !rhv);
	return (__strstr(lhv, rhv) != NULL);
}

#pragma GCC diagnostic pop
