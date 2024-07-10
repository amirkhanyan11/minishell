/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 20:13:28 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command * __result_use_check make_command(char * raw_cmd, t_shell *shell)
{
	if (!raw_cmd || !shell) return NULL;

	t_list *tokens = preprocess(tokenize(raw_cmd), shell);

	if (empty(tokens)) return NULL;

	t_command *cmd = __malloc(sizeof(t_command));

	cmd->options = make_list();
	cmd->args = make_list();
	cmd->name = __strdup(tokens->head->val);

	t_node *node = tokens->head->next;
	while (node)
	{
		if (node->val) // varables that couldn't reslove turn into null pointers, maybe better pop them
		{
			if (node->val[0] == '-')
				push_back(cmd->options, node->val);
			else
				push_back(cmd->args, node->val);
		}
		node = node->next;
	}

	list_clear(&tokens);

	cmd->resolved = false;

	return cmd;
}
