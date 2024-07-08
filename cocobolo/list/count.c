/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:19:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 16:41:02 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t count(t_list *list, t_list_value val)
{
	if (NULL == list) return 0;

	size_t res = 0;

	t_node *node = list->head;
	while (node)
	{
		if (__strstr(node->val, val) != NULL) res++;
		node = node->next;
	}
	return res;
}

size_t count_if(t_list *list, t_list_Countpredicate p)
{
	if (NULL == list || NULL == p) return 0;

	size_t res = 0;

	t_node *node = list->head;
	while (node)
	{
		if (p(node->val) == true) res++;
		node = node->next;
	}
	return res;
}
