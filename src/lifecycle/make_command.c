/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 17:05:30 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

t_command * __result_use_check make_command(char * raw_cmd)
{
	if (!raw_cmd || !shell) return NULL;

	// reset_descriptors(); // probably a bad choice considering pipes
	t_command *cmd = __malloc(sizeof(t_command));
	cmd->descriptors = make_descriptors();

	a_list tokens = preprocess(tokenize(raw_cmd), cmd);

	if (empty(tokens)) return NULL;


	cmd->shell = shell;
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

	cmd->resolved = false;

	return cmd;
}
