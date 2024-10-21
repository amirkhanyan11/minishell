/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:30:29 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/11 19:53:02 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char	*__strstr(char *haystack, char *needle)
{
	size_t	i;

	i = 0;
	if (!haystack || !needle)
		return (NULL);
	while (haystack[i])
	{
		if (__strcmp_weak__(haystack + i, needle) == true)
			return (haystack + i);
		i++;
	}
	return (NULL);
}
