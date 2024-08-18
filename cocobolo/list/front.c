/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:49:33 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:50:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

t_node 	*front(t_list *list)
{
	if (!list) return NULL;

	return list->head;
}


#pragma GCC diagnostic pop
