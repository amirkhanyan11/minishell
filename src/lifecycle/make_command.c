/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/18 19:52:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*make_command(t_list *tokens, t_cmd_container *container,
		t_shell *shell)
{
	t_command	*cmd;
	t_node		*possible_name;

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
	possible_name = tokens->head;
	while (possible_name && possible_name->next && is_redir(possible_name))
	{
		possible_name = possible_name->next->next;
	}

	bool no_name = (possible_name == NULL);

	if (!no_name)
		cmd->name = __strdup(possible_name->val);

	if (pop_redirections(cmd, tokens, container) == -1 || no_name || empty(tokens)
		|| sort_tokens(cmd, tokens) == -1 || cmd_lookup(cmd) == -1)
	{
		__t_command__(cmd);
		cmd = NULL;
	}
	return (cmd);
}
