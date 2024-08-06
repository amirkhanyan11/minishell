/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 15:37:32 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void eval(t_cmd_container *cmds, size_t i)
{
	if (NULL == cmds || i >= cmds->size || !cmds->arr[i]) return;

	t_command *cmd = cmds->arr[i];

	t_file		pipe[2];

	__pipe(pipe);

	if (i < cmds->size - 1)
	{
		dup2(pipe[out], STDOUT_FILENO);
	}

	// set_descriptors(cmd);

	if (cmd->type == builtin) cmd->eval(cmd);

	else if (cmd->type == program)
	{
		pid_t pid = __fork();
		if (0 == pid)
		{
			close(pipe[in]);
			cmd->eval(cmd);
		}
		// __eval_prog__(pipe, cmd);
	}

	dup2(pipe[in], STDIN_FILENO);

	dup2(cmd->shell->stddesc->stdout, STDOUT_FILENO);

	close(pipe[in]);
	close(pipe[out]);

	export_update(cmd->shell, "_", cmd->name);
	if (cmd->redirection & redirect_heredoc)
	{
		unlink(heredoc);
	    printf("\n"); // not here but in the end of all commands :)
	}
	// reset_descriptors(cmd);
}
