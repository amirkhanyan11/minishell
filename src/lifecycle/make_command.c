/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/21 17:48:59 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

t_command * make_command(t_list *tokens, t_cmd_container *container, t_shell *shell)
{
	if (empty(tokens) || !shell) return NULL;

	// reset_descriptors(); // probably a bad choice considering pipes
	t_command *cmd = __malloc(sizeof(t_command));
	cmd->descriptors = make_stddesc();

	cmd->shell = shell;
	cmd->container = container;
	cmd->options = make_list();
	cmd->args = make_list();
	cmd->name = __strdup(front(tokens)->val); // assume the name of the command goes always first in the input
	cmd->eval = NULL;
	cmd->redirection = 0;


	if (sort_tokens(cmd, tokens) == -1 || cmd_lookup(cmd) == -1)
	{
		__t_command__(&cmd);
	}

	return cmd;
}

#pragma GCC diagnostic pop

