/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/12 16:40:40 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void eval(t_cmd_container *cmds)
{
	if (NULL == cmds) return ;

	while (cmds->current_cmd_index < cmds->size)
	{
		t_command *cmd = cmds->arr[cmds->current_cmd_index];

		if (cmd)
		{
			cmd->eval(cmd);

			export_update(cmd->shell, "_", cmd->name);

			if (cmd->redirection & redirect_heredoc)
			{
				unlink(heredoc);
				printf("\n"); // not here but in the end of all commands :)
			}
		}
		cmds->current_cmd_index++;
	}
	while (-1 != wait(NULL));
}
