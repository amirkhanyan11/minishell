/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __str_starts_with.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:36:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/11 19:52:09 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

bool	__str_starts_with(const char *haystack, char *needle)
{
	if (!haystack || !needle || __strlen(haystack) < __strlen(needle))
		return (false);
	return (__strcmp_weak_n(haystack, needle));
}
