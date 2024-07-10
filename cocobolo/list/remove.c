/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:31:20 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 22:43:43 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void list_remove(t_list *list, t_node *node)
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
