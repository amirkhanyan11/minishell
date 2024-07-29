/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 21:24:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

			// if (i > 0)
			// 	{
			// 		dup2(cmds->arr[i - 1]->descriptors->stdout, cmds->arr[i]->descriptors->stdin);
			// 	}
			// 	if (i < cmds->size - 1)
			// 	{
					
			// 	}

// needs refactoring for pipes
void eval(t_cmd_container *cmds, size_t i)
{
	if (NULL == cmds || i >= cmds->size) return;

	t_file		pipe[2];

	__pipe(pipe);

	t_command *cmd = cmds->arr[i];

	// set_descriptors(cmd);

	if (i < cmds->size - 1)
	{
		dup2(pipe[out], STDOUT_FILENO);
	}
	
	if (list_value_same(cmd->name, "pwd")) pwd();

	else if (list_value_same(cmd->name, "history")) display_history();

	else if (list_value_same(cmd->name, "export")) export(cmd);

	else if (list_value_same(cmd->name, "echo")) echo(cmd);

	else if (list_value_same(cmd->name, "unset")) unset(cmd);

	else if (list_value_same(cmd->name, "env") || list_value_same(cmd->name, "printenv")) _env(cmd->name);

	else if (list_value_same(cmd->name, "cd")) cd(cmd);

	else eval_prog(pipe, cmds, i);
	
	if (i < cmds->size - 1)
	{
		// dup2(pipe[in], cmds->arr[i + 1]->descriptors->stdin);
		dup2(pipe[in], STDIN_FILENO);
	}
	
	dup2(cmd->shell->stddesc->stdout, STDOUT_FILENO);
	
	close(pipe[in]);
	close(pipe[out]);

	// reset_descriptors(cmd);
}
