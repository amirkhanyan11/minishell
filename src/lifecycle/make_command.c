/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:55:57 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// if (redirection_resolver(tokens, cmd) == -1) list_clear(&tokens);

t_command * make_command(t_list *tokens, t_shell *shell)
{
	if (empty(tokens) || !shell) return NULL;

	// reset_descriptors(); // probably a bad choice considering pipes
	t_command *cmd = __malloc(sizeof(t_command));
	cmd->descriptors = make_stddesc();

	cmd->shell = shell;
	cmd->options = make_list();
	cmd->args = make_list();
	cmd->name = __strdup(tokens->head->val); // assume the name of the command goes always first in the input
	cmd->resolved = false;
	cmd->redirection = 0;

	if (sort_tokens(cmd, tokens) == -1)
	{
		__t_command__(&cmd);
	}

	return cmd;
}
