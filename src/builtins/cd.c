/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:30:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/01 22:37:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void _chdir(const char *path)
{
	if (chdir(path) == -1)
		__perror(strerror(errno));
}

void cd(t_command *cmd)
{
	if (!cmd) return;

	if (!empty(cmd->args) && size(cmd->args) != 1)
	{
		__perror("cd : wrong arguments");
		return;
	}

	string oldpwd = get_value(cmd->shell->export, "PWD");

	if (empty(cmd->args) || find_range(cmd->args, "~", NULL))
	{
		string home = get_value(cmd->shell->export, "HOME");
		_chdir(home);
	}

	else if (size(cmd->args) == 1)
	{
		_chdir(cmd->args->head->val);
	}

	// replace with export_update()
	if (wd)
	{
		string pwd = __pwd__();
		export_update(cmd->shell, "OLDPWD", oldpwd);
		export_update(cmd->shell, "PWD", pwd);
	}
}
