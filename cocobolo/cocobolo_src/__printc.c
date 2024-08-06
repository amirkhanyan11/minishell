/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __printc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:53:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:17:54 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

void __unwrapped_printc__(const char * const message, ...)
{
	va_list args;
	va_start(args, message);

	t_printf_option function = va_arg(args, t_printf_option);

	while (NULL != function)
	{
		function(NULL);
		function = va_arg(args, t_printf_option);
	}

    printf("%s", message);
    __reset__(NULL);

	va_end(args);
}
