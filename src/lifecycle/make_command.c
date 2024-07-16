/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/16 18:11:44 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

t_command * __result_use_check make_command(char * raw_cmd)
{
	if (!raw_cmd || !shell) return NULL;

	reset_descriptors(); // probably a bad choice considering pipes

	t_list *tokens = preprocess(tokenize(raw_cmd));
	if (empty(tokens)) return NULL;

	t_command *cmd = __malloc(sizeof(t_command));

	cmd->options = make_list();
	cmd->args = make_list();
	cmd->name = __strdup(tokens->head->val); // assume the name of the command goes always first in the input

	t_node *node = tokens->head->next;

	while (node)
	{
		if (node->val[0] == '-')
			push_back(cmd->options, node->val);
		else
			push_back(cmd->args, node->val);
		node = node->next;
	}

	list_clear(&tokens);

	cmd->resolved = false;

	return cmd;
}
