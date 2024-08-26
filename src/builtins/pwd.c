/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:19:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/26 16:24:11 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SIZE 4096

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	pwd(t_command *cmd)
{
	eval_wrapper(cmd, _pwd);
}

void	__pwd__(t_command *cmd)
{
	int		status;
	char	*path;

	status = 0;
	if (invalid_option(cmd))
	{
		status = 1;
	}
	else
	{
		path = _getcwd();
		printf("%s\n", path);
		__delete_string(&path);
	}
	set_exit_status(status);
}

char	*_getcwd(void)
{
	char	*path;

	path = __malloc(SIZE + 1);
	if (NULL == getcwd(path, SIZE))
		path = __strappend(path, "/../", NULL);
	return (path);
}

#pragma GCC diagnostic pop
