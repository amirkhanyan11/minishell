/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:22:26 by aamirkha         ###   ########.fr       */
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

	t_node *token = tokens->head->next;

	while (token)
	{
		t_node *next = token->next;

		if (list_value_same(token->val, "<") || list_value_same(token->val, ">") || list_value_same(token->val, ">>") || list_value_same(token->val, "<<"))
		{
			if (-1 == redirect(token, cmd))
			{
				__t_command__(&cmd);
				return NULL;
			}

			next = token->next->next;
			erase(tokens, token, token->next);
		}

		else if (token->val[0] == '-')
			push_back(cmd->options, token->val);

		else
			push_back(cmd->args, token->val);

		token = next;

	}

	return cmd;
}
