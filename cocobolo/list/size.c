/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:01:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:36:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

size_t	__size__(t_node *head)
{
	if (!head)
		return (0);
	return (1 + (__size__(head->next)));
}

size_t	size(t_list *list)
{
	if (!list)
		return (0);
	return (__size__(list->head));
}

#pragma GCC diagnostic pop
