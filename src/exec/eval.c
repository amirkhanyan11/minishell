/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 18:17:57 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void eval(t_cmd_container *cmds)
{
	if (NULL == cmds || !cmds->arr[cmds->current_cmd_index]) return;

	t_command *cmd = cmds->arr[cmds->current_cmd_index];

	t_fd		pipe[PIPE_MAX];

	__pipe(pipe);

	if (cmds->current_cmd_index < cmds->size - 1)
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
