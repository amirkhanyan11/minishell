/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:40:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 22:40:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	pop_front(t_list *const list)
{
	t_node	*to_remove;

	if (NULL == list || NULL == list->head)
		return ;
	to_remove = list->head;
	list->head = list->head->next;
	free(to_remove);
}
