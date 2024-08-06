/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:54:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:55:32 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int sort_tokens(t_command *cmd, t_list *tokens)
{
	t_node *token = tokens->head->next;

	while (token)
	{
		t_node *next = token->next;

		if (string_equal(token->val, "<") || string_equal(token->val, ">") || string_equal(token->val, ">>") || string_equal(token->val, "<<"))
		{
			if (-1 == redirect(token, cmd))
			{
				return -1;
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
	return 0;
}

