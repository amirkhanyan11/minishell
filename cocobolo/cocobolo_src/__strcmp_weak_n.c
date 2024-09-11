/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __strcmp_weak_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:45:01 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/11 19:51:48 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

char	*__strcmp_weak_n(const char *lhv, const char *rhv)
{
	if (!lhv || !rhv)
		return (!lhv && !rhv);
	while (*lhv && *rhv)
	{
		if ((const unsigned char)*lhv != (const unsigned char)*rhv)
			return (NULL);
		lhv++;
		rhv++;
	}
	if (*lhv)
		return (lhv);
	return (rhv);
}
