/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:15:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:29:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char	*__strdup(const char *src)
{
	return (__strdup_until(src, '\0'));
}

char	*__strdup_until(const char *src, const char c)
{
	char	*dest;
	size_t	i;

	if (NULL == src)
		return (NULL);
	dest = __malloc(__strlen(src) + 1);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
