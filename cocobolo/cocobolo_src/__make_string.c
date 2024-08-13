/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __make_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:53:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/13 16:36:44 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char * __make_string_empty()
{
	char *s = __malloc(1);
	*s = '\0';
	return s;
}

char * __make_string_from_char(const char c)
{
	char *s = __malloc(2);
	s[0] = c;
	s[1] = '\0';
	return s;
}

char * __make_string_from_list(t_node *first, t_node *last)
{
	if (!first || !last) return NULL;

	char *res = __make_string_empty();

	t_node *curr = first;

	while (curr && curr->prev != last)
	{
		res = __strappend(res, curr->val);
		curr = curr->next;
	}
	return res;
}
