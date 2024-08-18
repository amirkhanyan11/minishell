/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:42:21 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:35:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static void	__pop__(t_node *const head)
{
	free(head->val);
	free(head);
}

void	list_clear(t_list **list)
{
	if (!list || !(*list))
		return ;
	postorder_traverse((*list)->head, __pop__);
	free(*list);
	*list = NULL;
}

#pragma GCC diagnostic pop
