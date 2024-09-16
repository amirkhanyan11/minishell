/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/16 20:16:17 by aamirkha         ###   ########.fr       */
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

	t_node *possible_name = tokens->head;

	while (possible_name && possible_name->next && is_redir(possible_name))
	{
		possible_name = possible_name->next->next;
	}

	if (possible_name == NULL)
	{
		__t_command__(cmd);
		cmd = NULL;
		return (NULL);
	}

	cmd->name = __strdup(possible_name->val);

	if (pop_redirections(cmd, tokens, container) == -1 || empty(tokens) || sort_tokens(cmd, tokens) == -1 || cmd_lookup(cmd) == -1)
	{
		__t_command__(cmd);
		cmd = NULL;
	}


	return (cmd);
}
