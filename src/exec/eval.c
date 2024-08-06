/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 18:39:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void eval(t_cmd_container *cmds)
{
	if (NULL == cmds || !cmds->arr[cmds->current_cmd_index]) return;

	t_command *cmd = cmds->arr[cmds->current_cmd_index];

	cmd->eval(cmd);

	export_update(cmd->shell, "_", cmd->name);

	if (cmd->redirection & redirect_heredoc)
	{
		unlink(heredoc);
	    printf("\n"); // not here but in the end of all commands :)
	}
}
