/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:30:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/31 16:59:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

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

	string wd = get_value(shell->export, "PWD");

	if (empty(cmd->args) || find_range(cmd->args, "~", NULL))
	{
		string home = get_value(shell->export, "HOME");
		_chdir(home);
	}

	else if (size(cmd->args) == 1)
	{
		_chdir(cmd->args->head->val);
	}

	// replace with export_update()
	if (wd)
	{
		string oldpwd = __strappend(__make_string_empty(), "OLDPWD", "=", wd);
		string cwd = __pwd__();
		string pwd = __strappend(__make_string_empty(), "PWD", "=", cwd);

		__export_from_string__(oldpwd);
		__export_from_string__(pwd);
	}
}
