/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:17:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:30:00 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

size_t	__strlen(const char *str)
{
	size_t	i;

	if (NULL == str)
		__exit("nullptr passed to __strlen");
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
