/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:42:21 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/05 22:45:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void __pop__(t_node * const head)
{
	free (head);
}

void list_clear(t_list *list)
{
	postorder_traverse(list->head, __pop__);
	list->head = NULL;
	list->tail = NULL;
}
