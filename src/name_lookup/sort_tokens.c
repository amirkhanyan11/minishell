/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:54:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 13:43:24 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

extern int	g_exit_status;

static int	sort_redirections(t_command *cmd, t_list *tokens);

int	sort_tokens(t_command *cmd, t_list *tokens)
{
	t_node	*token;

	if (sort_redirections(cmd, tokens) == -1)
		return (-1);
	token = front(tokens)->next;
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
	return (0);
}

static int	sort_redirections(t_command *cmd, t_list *tokens)
{
	t_node	*token;
	t_node	*next;

	token = front(tokens)->next;
	while (token)
	{
		next = token->next;
		if (string_equal(token->val, "<") || string_equal(token->val, ">")
			|| string_equal(token->val, ">>") || string_equal(token->val, "<<"))
		{
			if (!token->next || string_equal(token->next->val, ""))
			{
				__perror((token->next) ? "ambiguous redirect" : "syntax error");
					// amb redirect not for all commands
				g_exit_status = 258;
					// change
				return (-1);
			}
			else if (-1 == redirect(token, cmd))
			{
				set_exit_status(1);
				return (-1);
			}
			next = token->next->next;
			erase(tokens, token, token->next);
		}
		token = next;
	}
	return (0);
}

#pragma GCC diagnostic pop
