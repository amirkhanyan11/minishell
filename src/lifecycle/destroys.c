/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:30:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 19:39:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void __t_shell__(t_shell * shell)
{
    if (NULL == shell) return;

    list_clear(&shell->history);
    tree_clear(&shell->env);
    tree_clear(&shell->export);

	free(shell->stddesc);

    free(shell);

	shell = NULL;
}

void __t_command__(t_command **cmdptr)
{
	if (NULL == cmdptr) return;

	t_command *cmd = *cmdptr;

	if (NULL == cmd) return;

	list_clear(&cmd->args);
	list_clear(&cmd->options);
	reset_descriptors(cmd);

	free(cmd->descriptors);
		free(cmd->name);

	free(cmd);

	*cmdptr = NULL;
}

void __t_cmd_container__(t_cmd_container ** cmdsptr)
{
	if (NULL == cmdsptr) return;

	t_cmd_container *cmds = *cmdsptr;

	if (NULL == cmds) return;

	size_t i = 0;

	while (i < cmds->size)
	{
		__t_command__(&(cmds->arr[i]));
		i++;
	}

	cmds->shell->container = NULL;
	cmds->shell = NULL;

	free(cmds->arr);
	free(cmds);
	*cmdsptr = NULL;
}

#pragma GCC diagnostic pop
