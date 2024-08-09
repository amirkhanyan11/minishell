/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:33:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/09 19:16:06 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

bool	__strchr(char *s, const char c)
{
	while(*s)
	{
		if (*s == c) return true;
		++s;
	}
	return false;
}

char 		*__strchr_p(char *s, bool (*p) (char))
{
	while(*s)
	{
		if (p(*s) == true) break;
		++s;
	}
	return s;
}
