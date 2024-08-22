/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __perror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:56:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 19:35:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cocobolo.h>

#define __PROJECT_NAME__ "minishell: "

void	__perror(char *err)
{
	if (err)
	{
		write(STDERR_FILENO, __PROJECT_NAME__, __strlen(__PROJECT_NAME__));
		write(STDERR_FILENO, err, __strlen(err));
		write(STDERR_FILENO, "\n", 2);
	}
}

void	__va_perror(char *s, ...)
{
	va_list	args;
	char	*arg;
	char	*res;

	if (!s)
		return;
	va_start(args, s);
	arg = va_arg(args, char *);
	res = __strdup(s);
	while (NULL != arg)
	{
		res = __single_append__(res, arg);
		arg = va_arg(args, char *);
	}
	va_end(args);

	__perror(res);
	__delete_string(&res);
}
