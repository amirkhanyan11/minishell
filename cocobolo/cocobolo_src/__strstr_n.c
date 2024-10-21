/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strstr_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:53:32 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/11 19:54:43 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char	*__strstr_n(char *haystack, char *needle)
{
	size_t	i;
	char	*guess;

	i = 0;
	if (!haystack || !needle)
		return (NULL);
	while (haystack[i])
	{
		guess = __strcmp_weak_n(haystack + i, needle);
		if (guess)
			return (guess);
		i++;
	}
	return (NULL);
}
