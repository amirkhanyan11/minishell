/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:39:26 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/01 01:13:50 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void killall(t_cmd_container *container);
static void	execute(t_command *cmd, t_fd *pipe, t_eval_opcode opcode);
static void	not_funny(t_command *cmd, t_fd *pipe);

void	eval_wrapper(t_command *cmd, t_eval_opcode opcode)
{
	t_fd	pipes[PIPE_MAX];

	if (pipe(pipes) == -1)
		return killall(cmd->container);
	if (cmd->container->current_cmd_index < cmd->container->size - 1)
		dup2(pipes[out], STDOUT_FILENO);
	set_descriptors(cmd);
	execute(cmd, pipes, opcode);
	dup2(pipes[in], STDIN_FILENO);
	dup2(cmd->shell->stddesc->stdout, STDOUT_FILENO);
	close(pipes[in]);
	close(pipes[out]);
}

static void	execute(t_command *cmd, t_fd *pipes, t_eval_opcode opcode)
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
		not_funny(cmd, pipes);
}

static void	not_funny(t_command *cmd, t_fd *pipes)
{
	int		s;

	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		cmd->pid = -1;
		return killall(cmd->container);
	}
	if (0 == cmd->pid)
	{
		close(pipes[in]);
		__eval_prog__(cmd);
	}
	if (cmd->container->current_cmd_index == cmd->container->size - 1)
	{
		waitpid(cmd->pid, &s, 0);
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

static void killall(t_cmd_container *container)
{
	size_t	i;

	container->arr[container->current_cmd_index]->pid = -1;

	i = 0;
	while (i < container->current_cmd_index)
	{
		if (container->arr[i] && container->arr[i]->pid > -1)
		{
			kill(container->arr[i]->pid, SIGKILL);
			waitpid(container->arr[i]->pid, NULL, 0);
			container->arr[i]->pid = -1;
		}
		i++;
	}
	__perror("fork: Resource temporarily unavailable");
}
