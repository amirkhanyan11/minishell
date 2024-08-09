/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:54:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/09 18:53:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int sort_redirections(t_command *cmd, t_list *tokens);

int sort_tokens(t_command *cmd, t_list *tokens)
{
	if (sort_redirections(cmd, tokens) == -1)
	{
		set_exit_status(1);
		return -1;
	}

	t_node *token = tokens->head->next;

	while (token && token->val && token->val[0] == '-')
	{
		push_back(cmd->options, token->val);
		token = token->next;
	}

	while (token)
	{
		push_back(cmd->args, token->val);
		token = token->next;
	}

	return 0;
}

static int sort_redirections(t_command *cmd, t_list *tokens)
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
		token = next;
	}
	return 0;
}
