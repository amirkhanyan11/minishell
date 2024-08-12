/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:30:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/12 22:20:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void update_pwd(t_shell *shell, char *oldpwd);
static void __cd_one_arg__(t_command *cmd);
static void _chdir(const char *path, int *status);
static void __cd_no_arg__(t_command *cmd);

void cd(t_command *cmd)
{
	eval_wrapper(cmd, _cd);
}

void __cd__(t_command *cmd)
{
	if (!cmd) return;

	if (size(cmd->options) >= 1 || (size(cmd->options) == 1  && !string_equal(cmd->options->head->val, "-")))
	{
		set_exit_status(2);
		scoped_string msg = __make_string("cd: ", cmd->options->head->val, ": invalid option");
		__perror(msg);
		return ;
	}

	list_move_back(cmd->options, cmd->args);

	char *oldpwd = get_val(cmd->shell->export, "PWD");

	if (empty(cmd->args)) __cd_no_arg__(cmd);

	else __cd_one_arg__(cmd);

	update_pwd(cmd->shell, oldpwd);

}

static void _chdir(const char *path, int *status)
{
	if (chdir(path) == -1)
	{
		*status = 1;
		__perror(strerror(errno));
	}
}

static void __cd_no_arg__(t_command *cmd)
{
	int status = 0;

	char *home = get_val(cmd->shell->export, "HOME");

	_chdir(home, &status);

	set_exit_status(status);
}

static void __cd_one_arg__(t_command *cmd)
{

	int status = 0;

	if (find_range(cmd->args, "-", NULL) != NULL)
	{
		char *path = get_val(cmd->shell->export, "OLDPWD");
		if (!path || *path == '\0')
		{
			status = 1;
			__perror("cd: OLDPWD not set");
		}
		else
		{
			_chdir(path, &status);
			pwd(cmd); // debatable
		}
	}
	else if (find_range(cmd->args, "~", NULL))
	{
		__cd_no_arg__(cmd);
		return;
	}
	else
		_chdir(cmd->args->head->val, &status);

	set_exit_status(status);
}

static void update_pwd(t_shell *shell, char *oldpwd)
{
	if (!shell || !oldpwd) return;

	scoped_string pwd = _getcwd();
	export_update(shell, "OLDPWD", oldpwd);
	export_update(shell, "PWD", pwd);
}
