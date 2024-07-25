/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/25 17:53:43 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// needs refactoring for pipes
void eval(t_command *cmd)
{
	set_descriptors(cmd->shell);

	if (0 == __strcmp(cmd->name, "pwd")) pwd();

	else if (0 == __strcmp(cmd->name, "history")) display_history();

	else if (0 == __strcmp(cmd->name, "export")) export(cmd);

	else if (0 == __strcmp(cmd->name, "echo")) echo(cmd);

	else if (0 == __strcmp(cmd->name, "unset")) unset(cmd);

	else if (0 == __strcmp(cmd->name, "env") || 0 == __strcmp(cmd->name, "printenv")) _env(cmd->name);

	else if (0 == __strcmp(cmd->name, "cd")) cd(cmd);

	else
	{
		pid_t pid = __fork();
		if (0 == pid)
		{
			eval_prog(cmd);
		}
		int x = 0;
		waitpid(pid, &x, 0);
		cmd->shell->status = WEXITSTATUS(x);	
	}
	reset_descriptors(cmd->shell);
}
