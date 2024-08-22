/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:32:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 14:12:44 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	set_descriptors(t_command *cmd)
{
	if (!cmd)
		return ;
	if (cmd->redirection & redirect_in)
		dup2(cmd->descriptors->stdin, STDIN_FILENO);
	if (cmd->redirection & redirect_out)
		dup2(cmd->descriptors->stdout, STDOUT_FILENO);
}

#pragma GCC diagnostic pop
