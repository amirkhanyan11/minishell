/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:15:52 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 19:49:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char	* __attribute__((warn_unused_result)) __strdup(const char *src)
{
	char	*dest;
	size_t	i;

	if (NULL == src) __exit("nullptr passed to __strdup");

	dest = __malloc(__strlen(src) + 1);

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
