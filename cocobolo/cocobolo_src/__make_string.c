/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __make_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:53:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 17:48:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char * __attribute__((malloc)) __attribute__((warn_unused_result)) __make_string_empty()
{
	char *s = __malloc(1);
	*s = '\0';
	return s;
}

char * __attribute__((malloc)) __attribute__((warn_unused_result)) __make_string_from_list(t_list *list)
{
	if (!list) return NULL;

	char *res = __make_string_empty();

	t_node *node = list->head;
	while (node)
	{
		res = __strappend(res, node->val);
		node = node->next;
	}
	return res;
}
