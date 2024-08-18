/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:01:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:53:08 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void __single__push_front__(t_list *const list, const t_list_value x)
{
	if (!list) return;

	t_node *node = make_node(x);
	node->next = list->head;

	if (NULL == list->tail)
		list->tail = node;

	if (list->head) list->head->prev = node;

	list->head = node;
}

#pragma GCC diagnostic pop
