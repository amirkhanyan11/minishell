/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:30:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 23:00:52 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void update_pwd(t_shell *shell, char *oldpwd);
static void cd_one_arg(t_command *cmd);
static void cd_no_arg(t_command *cmd);
static void _chdir(const char *path);

void cd(t_command *cmd)
{
	if (!cmd) return;

	list_move_back(cmd->options, cmd->args);

	if (!empty(cmd->args) && size(cmd->args) != 1)
	{
		__perror("cd : wrong arguments");
		return;
	}

	string oldpwd = get_value(cmd->shell->export, "PWD");

	if (empty(cmd->args)) cd_no_arg(cmd);

	else cd_one_arg(cmd);

	update_pwd(cmd->shell, oldpwd);
}

static void _chdir(const char *path)
{
	if (chdir(path) == -1)
		__perror(strerror(errno));
}

static void cd_no_arg(t_command *cmd)
{
	string home = get_value(cmd->shell->export, "HOME");
	_chdir(home);

}

static void cd_one_arg(t_command *cmd)
{
	if (find_range(cmd->args, "-", NULL) != NULL)
	{
		string path = get_value(cmd->shell->export, "OLDPWD");
		if (!path || *path == '\0')
		{
			__perror("cd: OLDPWD not set");
		}
		else
		{
			_chdir(path);
			pwd();
		}
	}
	else if (find_range(cmd->args, "~", NULL))
	{
		cd_no_arg(cmd);
	}
	else
		_chdir(cmd->args->head->val);

}

static void update_pwd(t_shell *shell, char *oldpwd)
{
	if (!shell || !oldpwd) return;

	string pwd = __pwd__();
	export_update(shell, "OLDPWD", oldpwd);
	export_update(shell, "PWD", pwd);
}
