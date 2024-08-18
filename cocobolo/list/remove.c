/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:31:20 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:53:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void pop(t_list *list, t_node *node)
{
	if (!list || !node) return;

	if (node == list->head) pop_front(list);

	else if (node == list->tail) pop_back(list);

	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;

		free(node->val);
		free(node);
	}
}

size_t list_remove(t_list *list, t_list_value val)
{
	return list_remove_if(list, val, list_value_same);
}

size_t list_remove_if(t_list *list, t_list_value val, t_list_Bpredicate_val p)
{
	if (!list || empty(list) || !val) return 0;

	size_t removed = 0;

	t_node *node = list->head;

	while (node)
	{
		t_node *next = node->next;
		if (p(node->val, val) == true)
		{
			pop(list, node);
			removed++;
		}
		node = next;
	}
	return removed;
}

#pragma GCC diagnostic pop
