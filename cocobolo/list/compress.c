/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:20:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/18 23:04:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void list_compress(t_list *list, t_node *first, t_node *last)
{
	if (!list || !first || !last || first == last)
		return;

	while (first && first->next && first->next != last)
	{
		first->val = __strappend(first->val, first->next->val, NULL);
		pop(list, first->next);
	}
	first->val = __strappend(first->val, last->val, NULL);
	pop(list, last);
}
