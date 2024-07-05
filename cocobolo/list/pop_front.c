/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:36:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 22:40:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void pop_front(t_list *const list)
{
	if (NULL == list || NULL == list->tail) return;

	t_node *to_remove = list->tail;

	list->tail = list->tail->prev;

	free(to_remove);
}
