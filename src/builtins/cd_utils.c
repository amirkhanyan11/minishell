/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:57:53 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/22 18:49:30 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static void	cd_minus(int *status, t_command *cmd);

void	_chdir(t_command *cmd, const char *path, int *status)
{
	scoped_string	cwd;

	cwd = _getcwd();
	if (chdir(path) == -1)
	{
		*status = 1;
		__va_perror("cd: ", path, ": No such file or directory");
		return ;
	}
	if (cmd->container->size == 1 && errno == ENOENT)
	{
		__perror("cd: error retrieving current directory: getcwd:"
			"cannot access parent directories: No such file or directory");
	}
	if (cmd->container->size > 1)
	{
		chdir(cwd);
	}
}

void	__cd_no_arg__(t_command *cmd)
{
	int		status;
	char	*home;

	status = 0;
	home = get_val(cmd->shell->export, "HOME");
	if (!home)
		home = get_val(cmd->shell->export, "__HOME_CACHE__");
	if (!home)
	{
		status = 1;
		__perror("cd: HOME not set");
	}
	else
		_chdir(cmd, home, &status);
	set_exit_status(status);
}

void	__cd_one_arg__(t_command *cmd)
{
	int	status;

	status = 0;
	if (find_range(cmd->args, "-", NULL) != NULL)
	{
		cd_minus(&status, cmd);
	}
	else if (find_range(cmd->args, "~", NULL))
	{
		__cd_no_arg__(cmd);
		return ;
	}
	else
		_chdir(cmd, front(cmd->args)->val, &status);
	set_exit_status(status);
}

void	cd_minus(int *status, t_command *cmd)
{
	char	*path;

	path = get_val(cmd->shell->export, "OLDPWD");
	if (!path || *path == '\0')
	{
		*status = 1;
		__perror("cd: OLDPWD not set");
	}
	else
	{
		_chdir(cmd, path, status);
		pwd(cmd);
	}
}

void	update_pwd(t_shell *shell, char *oldpwd)
{
	scoped_string	pwd;

	if (!shell || !oldpwd)
		return ;
	pwd = _getcwd();
	export_update(shell, "OLDPWD", oldpwd);
	export_update(shell, "PWD", pwd);
}

#pragma GCC diagnostic pop
