/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strtrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:19:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:18:54 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

static void	_move_ptrs(char **left, char **right, char  *set);

char	* __strtrim(char *s1, char  *set)
{
	char	*left;
	char	*right;

	if (!s1 || !set)
		return (NULL);
	left = (char *)s1;
	right = ((char *)s1) + __strlen(s1) - 1;
	_move_ptrs(&left, &right, set);
	if (left > right)
		return (__make_string_empty());

	char * res = __strdup(left);

	res[right - left + 1] = '\0';

	return res;
}

static	void	_move_ptrs(char **left, char **right, char *set)
{
	while (((*left)) && __strchr(set, **left))
		++(*left);
	while (((*right) >= (*left)) && __strchr(set, **right))
		--(*right);
}

static char	*_allocate_null(void)
{
	char	*dst;

	dst = (char *)malloc(1);
	*dst = '\0';
	return (dst);
}
