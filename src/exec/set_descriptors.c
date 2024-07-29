/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:32:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 17:16:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void set_descriptors(t_command * cmd)
{
	if (!cmd) return ;

	if (cmd->descriptors->stdin != cmd->shell->stddesc->stdin)
		dup2(cmd->descriptors->stdin, STDIN_FILENO);
	if (cmd->descriptors->stdout != cmd->shell->stddesc->stdout)
		dup2(cmd->descriptors->stdout, STDOUT_FILENO);
	if (cmd->descriptors->stderr != cmd->shell->stddesc->stderr)
		dup2(cmd->descriptors->stderr, STDERR_FILENO);
}
