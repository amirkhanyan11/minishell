/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:42:21 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/16 21:28:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void __pop__(t_node * const head)
{
	free(head->val);
	free (head);
}

void list_clear(t_list **list)
{
	if (!list || !(*list)) return;
	
	postorder_traverse((*list)->head, __pop__);
	free(*list);
	*list = NULL;
}
