/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __make_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:53:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:28:52 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char	*__make_string_empty(void)
{
	char	*s;

	s = __malloc(1);
	*s = '\0';
	return (s);
}

char	*__make_string_from_char(const char c)
{
	char	*s;

	s = __malloc(2);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

char	*__make_string_from_list(t_node *first, t_node *last)
{
	char	*res;
	t_node	*curr;

	if (!first || !last)
		return (NULL);
	res = __make_string_empty();
	curr = first;
	while (curr && curr->prev != last)
	{
		res = __strappend(res, curr->val);
		curr = curr->next;
	}
	return (res);
}
