/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:55:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/13 17:23:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_node * list_insert(t_list *list, t_node *pos, char *val)
{
	if(list == NULL || pos == NULL || !val) return NULL;

	if(empty(list) || pos == list->tail)
	{
		push_back(list, val);
		return list->tail;
	}
	t_node *new = make_node(val);

	new->prev = pos;
	pos->next->prev = new;
	new->next = pos->next;
	pos->next = new;
	return new;
}
