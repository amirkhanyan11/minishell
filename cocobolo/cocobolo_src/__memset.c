/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __memset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:57:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 19:57:44 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void	*__memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i++] = (unsigned char)c;
	}
	return (b);
}
