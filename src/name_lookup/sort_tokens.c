/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:54:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/26 16:03:47 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static int	sort_redirections(t_command *cmd, t_list *tokens);
static int	sort_redirections_the_good_part(t_command *cmd, t_list *tokens,
				t_node *token);

int	sort_tokens(t_command *cmd, t_list *tokens)
{
	t_node	*token;

	if (sort_redirections(cmd, tokens) == -1)
		return (-1);
	token = front(tokens)->next;
	while (token && token->val && token->val[0] == '-')
	{
		push_back(cmd->options, token->val, NULL);
		token = token->next;
	}
	while (token)
	{
		push_back(cmd->args, token->val, NULL);
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
			if (sort_redirections_the_good_part(cmd, tokens, token) == -1)
				return (-1);
			next = token->next->next;
			erase(tokens, token, token->next);
		}
		token = next;
	}
	return (0);
}

static int	sort_redirections_the_good_part(t_command *cmd, t_list *tokens,
		t_node *token)
{
	if (!token->next || string_equal(token->next->val, ""))
	{
		if (token->next)
		{
			set_exit_status(1);
			__perror("ambiguous redirect");
		}
		else
			__perror("syntax error");
		set_exit_status_no_of(258);
		return (-1);
	}
	else if (-1 == redirect(token, cmd))
	{
		set_exit_status(1);
		return (-1);
	}
	return (0);
}

#pragma GCC diagnostic pop
