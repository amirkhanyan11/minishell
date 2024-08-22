/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_descriptors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:24:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 14:12:52 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	reset_descriptors(t_command *cmd)
{
	if (!cmd || !cmd->shell)
		return ;
	if (cmd->descriptors->stdin != cmd->shell->stddesc->stdin)
	{
		close(cmd->descriptors->stdin);
		dup2(cmd->shell->stddesc->stdin, STDIN_FILENO);
	}
	if (cmd->descriptors->stdout != cmd->shell->stddesc->stdout)
	{
		close(cmd->descriptors->stdout);
		dup2(cmd->shell->stddesc->stdout, STDOUT_FILENO);
	}
	if (cmd->descriptors->stderr != cmd->shell->stddesc->stderr)
	{
		close(cmd->descriptors->stderr);
		dup2(cmd->shell->stddesc->stderr, STDERR_FILENO);
	}
}
#pragma GCC diagnostic pop
