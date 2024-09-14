/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/15 00:45:56 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*make_command(t_list *tokens, t_cmd_container *container,
		t_shell *shell)
{
	t_command	*cmd;

	if (empty(tokens) || !shell)
		return (NULL);
	cmd = __calloc(sizeof(t_command));
	cmd->descriptors = make_stddesc();
	cmd->shell = shell;
	cmd->pid = -1337;
	cmd->container = container;
	cmd->options = make_list();
	cmd->args = make_list();
	cmd->eval = NULL;
	cmd->redirection = 0;
	cmd->name = __strdup(tokens->head->val);

	if (pop_redirections(cmd, tokens, container) == -1 || empty(tokens) || sort_tokens(cmd, tokens) == -1 || cmd_lookup(cmd) == -1)
	{
		if (cmd->redirection & redirect_heredoc)
		{
			unlink(HEREDOC);
		}
		__t_command__(cmd);
		cmd = NULL;
	}
	return (cmd);
}
