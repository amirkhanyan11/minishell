/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:30:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 17:21:21 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void update_pwd(t_shell *shell, char *oldpwd);
static void __cd_one_arg__(t_command *cmd);
static void __cd_no_arg__(t_command *cmd);
static void _chdir(const char *path);

void cd(t_command *cmd)
{
	eval_wrapper(cmd, code_cd);
}

void __cd__(t_command *cmd)
{
	if (!cmd) return;

	list_move_back(cmd->options, cmd->args);

	if (!empty(cmd->args) && size(cmd->args) != 1)
	{
		__perror("cd : wrong arguments");
		return;
	}

	char *oldpwd = get_val(cmd->shell->export, "PWD");

	if (empty(cmd->args)) __cd_no_arg__(cmd);

	else __cd_one_arg__(cmd);

	update_pwd(cmd->shell, oldpwd);
}

static void _chdir(const char *path)
{
	if (chdir(path) == -1)
		__perror(strerror(errno));
}

static void __cd_no_arg__(t_command *cmd)
{
	char *home = get_val(cmd->shell->export, "HOME");
	_chdir(home);

}

static void __cd_one_arg__(t_command *cmd)
{
	if (find_range(cmd->args, "-", NULL) != NULL)
	{
		char *path = get_val(cmd->shell->export, "OLDPWD");
		if (!path || *path == '\0')
		{
			__perror("cd: OLDPWD not set");
		}
		else
		{
			_chdir(path);
			pwd(cmd); // debatable
		}
	}
	else if (find_range(cmd->args, "~", NULL))
	{
		__cd_no_arg__(cmd);
	}
	else
		_chdir(cmd->args->head->val);

}

static void update_pwd(t_shell *shell, char *oldpwd)
{
	if (!shell || !oldpwd) return;

	scoped_string pwd = _getcwd();
	export_update(shell, "OLDPWD", oldpwd);
	export_update(shell, "PWD", pwd);
}
