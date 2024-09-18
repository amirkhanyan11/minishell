/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __str_ends_with.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:32:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/18 19:46:34 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

bool	__str_ends_with(const char *haystack, const char *needle)
{
	size_t	haystack_l;
	size_t	needle_l;

	if (!haystack || !needle)
		return (false);
	haystack_l = __strlen(haystack);
	needle_l = __strlen(needle);
	if (haystack_l < needle_l)
		return (false);
	return (string_equal(haystack + haystack_l - needle_l, needle));
}
