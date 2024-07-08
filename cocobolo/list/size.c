/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:01:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 17:03:01 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t __size__(t_node *head)
{
	if (!head) return 0;
	return 1 + (__size__(head->next));
}

size_t size(t_list *list)
{
	if (!list) return 0;

	return __size__(list->head);
}
