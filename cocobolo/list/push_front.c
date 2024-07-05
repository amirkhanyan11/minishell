/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:01:03 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 22:23:13 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void push_front(t_list *const list, const t_list_value x)
{
	if (!list) return;

	t_node *node = make_node(x);
	node->next = list->head;

	if (NULL == list->tail)
		list->tail = node;

	if (list->head) list->head->prev = node;

	list->head = node;
}
