/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:33:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 22:35:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	push_back(t_list *list, ...)
{
	va_list	args;
	char	*arg;

	va_start(args, list);
	arg = va_arg(args, char *);
	while (NULL != arg)
	{
		__single__push_back__(list, arg);
		arg = va_arg(args, char *);
	}
	va_end(args);
}
void	push_front(t_list *list, ...)
{
	va_list	args;
	char	*arg;

	va_start(args, list);
	arg = va_arg(args, char *);
	while (NULL != arg)
	{
		__single__push_front__(list, arg);
		arg = va_arg(args, char *);
	}
	va_end(args);
}
#pragma GCC diagnostic pop
