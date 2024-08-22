/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:19:13 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/21 19:13:29 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SIZE 4096

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	__pwd__(t_command *cmd)
{
	eval_wrapper(cmd, _pwd);
}

void	pwd(t_command *cmd)
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
		__delete_string(&path);
		printf("%s\n", path);
	}
	set_exit_status(status);
}

char	*_getcwd(void)
{
	char	*path;

	path = __malloc(SIZE + 1);
	if (NULL == getcwd(path, SIZE))
		path = __strappend(path, "/../");
	return (path);
}

#pragma GCC diagnostic pop
