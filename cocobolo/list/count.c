/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:19:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/16 18:36:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t count(t_node *first, t_node *last, t_list_value val)
{
	if (NULL == first || NULL == last) return 0;

	size_t res = 0;

	while (first && first->prev != last)
	{
		if (__strstr(first->val, val) != NULL) res++;
		first = first->next;
	}
	return res;
}

size_t count_range(t_list *list, t_list_value val)
{
	if (NULL == list) return 0;

	return count(list->head, list->tail, val);
}

size_t count_if(t_node *first, t_node *last, t_list_Countpredicate p)
{
	if (NULL == first || NULL == last || NULL == p) return 0;

	size_t res = 0;

	while (first && first->prev != last)
	{
		if (p(first->val) == true) res++;
		first = first->next;
	}
	return res;
}
