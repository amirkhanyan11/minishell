/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 00:58:57 by aamirkha         ###   ########.fr       */
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
	
	set_descriptors(cmd);
	
	if (list_value_same(cmd->name, "pwd")) pwd();

	else if (list_value_same(cmd->name, "history")) display_history();

	else if (list_value_same(cmd->name, "export")) export(cmd);

	else if (list_value_same(cmd->name, "echo")) echo(cmd);

	else if (list_value_same(cmd->name, "unset")) unset(cmd);

	else if (list_value_same(cmd->name, "env") || list_value_same(cmd->name, "printenv")) _env(cmd->name);

	else if (list_value_same(cmd->name, "cd")) cd(cmd);

	else eval_prog(pipe, cmds, i);
	
	dup2(pipe[in], STDIN_FILENO);
	
	dup2(cmd->shell->stddesc->stdout, STDOUT_FILENO);
	
	close(pipe[in]);
	close(pipe[out]);

	export_update(cmds->arr[i]->shell, "_", cmds->arr[i]->name);
	// reset_descriptors(cmd);
}
