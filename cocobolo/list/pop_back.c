/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:40:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 23:26:36 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void pop_back(t_list *const list)
{
	if (NULL == list || NULL == list->tail) return;

	t_node *to_remove = list->tail;

	list->tail = list->tail->prev;

	list->tail->next = NULL;

	free(to_remove->val);
	free(to_remove);
}