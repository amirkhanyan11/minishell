/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unwrapped_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:28:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/07 15:39:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void __attribute__((sentinel))  __unwrapped_push__(f_push f, t_list *const list, ...)
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