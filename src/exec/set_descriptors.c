/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:32:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 15:25:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	set_descriptors(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->redirection & redirect_in)
		dup2(cmd->descriptors->stdin, STDIN_FILENO);
	if (cmd->redirection & redirect_out)
		dup2(cmd->descriptors->stdout, STDOUT_FILENO);
}

#pragma GCC diagnostic pop
