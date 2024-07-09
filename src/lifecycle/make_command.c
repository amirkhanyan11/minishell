/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 21:00:30 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command * __attribute__((warn_unused_result)) make_command(char * raw_cmd, t_shell *shell)
{
	t_command *cmd = __malloc(sizeof(t_command));

	t_list *tokens = preprocess(tokenize(raw_cmd), shell);

	if (empty(tokens)) __exit("empty input");

	cmd->options = make_list();
	cmd->args = make_list();
	cmd->name = __strdup(tokens->head->val);

	t_node *node = tokens->head->next;
	while (node)
	{
		if (node->val[0] == '-')
		{
			push_back(cmd->options, node->val);
		}
		else push_back(cmd->args, node->val);

		node = node->next;
	}

	list_clear(&tokens);

	return cmd;
}
