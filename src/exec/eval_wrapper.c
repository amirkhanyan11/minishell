/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:39:26 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/31 22:41:02 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static void	execute(t_command *cmd, t_fd *pipe, t_eval_opcode opcode);
static void	not_funny(t_command *cmd, t_fd *pipe);

void	eval_wrapper(t_command *cmd, t_eval_opcode opcode)
{
	t_fd	pipe[PIPE_MAX];

	__pipe(pipe);
	if (cmd->container->current_cmd_index < cmd->container->size - 1)
		dup2(pipe[out], STDOUT_FILENO);
	set_descriptors(cmd);
	execute(cmd, pipe, opcode);
	dup2(pipe[in], STDIN_FILENO);
	dup2(cmd->shell->stddesc->stdout, STDOUT_FILENO);
	close(pipe[in]);
	close(pipe[out]);
}

static void	execute(t_command *cmd, t_fd *pipe, t_eval_opcode opcode)
{
	if (_cd == opcode)
		__cd__(cmd);
	else if (_echo == opcode)
		__echo__(cmd);
	else if (_env == opcode)
		__env__(cmd);
	else if (_export == opcode)
		__export__(cmd);
	else if (_history == opcode)
		__history__(cmd);
	else if (_pwd == opcode)
		__pwd__(cmd);
	else if (_unset == opcode)
		__unset__(cmd);
	else if (_msh_exit == opcode)
		__exit__(cmd);
	else if (_program == opcode)
		not_funny(cmd, pipe);
}

static void	not_funny(t_command *cmd, t_fd *pipe)
{
	int		s;
	pid_t	pid;

	pid = __fork();
	if (0 == pid)
	{
		close(pipe[in]);
		__eval_prog__(cmd);
	}
	if (cmd->container->current_cmd_index == cmd->container->size - 1)
	{
		waitpid(pid, &s, 0);
		if (WIFSIGNALED(s))
		{
			s = WTERMSIG(s) + 128;
			if (s == 131)
				printf("Quit: 3\n");
			set_exit_status(s);
		}
		else
			set_exit_status(WEXITSTATUS(s));
	}
}

#pragma GCC diagnostic pop
