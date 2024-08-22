/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:21:05 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 19:37:40 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char	*__single_append__(char *lhv, char *rhv)
{
	char	*target;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!lhv || !rhv)
		return (lhv);
	i = 0;
	j = 0;
	k = 0;
	target = (char *)__malloc(__strlen(lhv) + __strlen(rhv) + 1);
	if (!target)
		return (NULL);
	while (lhv[i] || rhv[j])
	{
		if (lhv[i])
			target[k++] = lhv[i++];
		else
			target[k++] = rhv[j++];
	}
	target[k] = '\0';
	free(lhv);
	return (target);
}

char	*__strappend(char *s, ...)
{
	va_list	args;
	char	*arg;

	va_start(args, s);
	arg = va_arg(args, char *);
	while (NULL != arg)
	{
		s = __single_append__(s, arg);
		arg = va_arg(args, char *);
	}
	va_end(args);
	return (s);
}
