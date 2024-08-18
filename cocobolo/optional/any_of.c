/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:03:33 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:06:08 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cocobolo.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

bool	any_of(t_optional_predicate unary_predicate, ...)
{
	bool				res;
	const t_optional	*current;
	va_list				arglist;

	res = false;
	va_start(arglist, unary_predicate);
	current = va_arg(arglist, t_optional *);
	while (current != NULL)
	{
		if (unary_predicate(current) == true)
		{
			res = true;
			break ;
		}
		current = va_arg(arglist, t_optional *);
	}
	va_end(arglist);
	return (res);
}

#pragma GCC diagnostic pop
