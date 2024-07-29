/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 17:25:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// needs refactoring for pipes
void eval(t_command *cmd)
{
	set_descriptors(cmd);

	if (list_value_same(cmd->name, "pwd")) pwd();

	else if (list_value_same(cmd->name, "history")) display_history();

	else if (list_value_same(cmd->name, "export")) export(cmd);

	else if (list_value_same(cmd->name, "echo")) echo(cmd);

	else if (list_value_same(cmd->name, "unset")) unset(cmd);

	else if (list_value_same(cmd->name, "env") || list_value_same(cmd->name, "printenv")) _env(cmd->name);

	else if (list_value_same(cmd->name, "cd")) cd(cmd);

	else eval_prog(cmd);
		
	reset_descriptors(cmd);
}
