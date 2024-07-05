/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:58:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 22:20:52 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void push_back(t_list *const list, const t_list_value x)
{
	if (!list) return;

	t_node *node = make_node(x);
	node->prev = list->tail;

	if (NULL == list->head)
		list->head = node;

	if (list->tail) list->tail->next = node;
	
	list->tail = node;
}
