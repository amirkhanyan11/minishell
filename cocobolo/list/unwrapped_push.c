/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unwrapped_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:28:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:52:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void __unwrapped_push__(f_push f, t_list *const list, ...)
{
	va_list args;
	va_start(args, list);

	char *arg = va_arg(args, char *);

	while (NULL != arg)
	{
		f(list, arg);
		arg = va_arg(args, char *);
	}

	va_end(args);
}

#pragma GCC diagnostic pop
