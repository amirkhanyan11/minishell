/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/22 22:38:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell * shell;

void eval(t_command *cmd)
{
	set_descriptors();

	if (0 == __strcmp(cmd->name, "pwd")) pwd();

	else if (0 == __strcmp(cmd->name, "history")) display_history();

	else if (0 == __strcmp(cmd->name, "export")) export(cmd);

	else if (0 == __strcmp(cmd->name, "echo")) echo(cmd);

	else if (0 == __strcmp(cmd->name, "unset")) unset(cmd);

	else if (0 == __strcmp(cmd->name, "env") || 0 == __strcmp(cmd->name, "printenv")) _env(cmd->name);

	else if (0 == __strcmp(cmd->name, "cd")) cd(cmd);

	else eval_prog(cmd);

	reset_descriptors();
}
