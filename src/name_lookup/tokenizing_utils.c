/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:29:11 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/18 22:04:38 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_parse(t_list *tokens)
{
	bool	d;
	bool	s;
	t_node	*token;

	d = false;
	s = false;
	token = tokens->head;
	while (token)
	{
		if (!d && string_equal(token->val, "\'"))
			s = !s;
		if (!s && string_equal(token->val, "\""))
			d = !d;
		token = token->next;
	}
	if (d || s)
	{
		if (d)
			__perror("parse error near token \"");
		else
			__perror("parse error near token \'");
		return (-1);
	}
	return (0);
}

int	parenthesis_parse(t_list *tokens)
{
	t_node	*token;

	t_list *stack = make_list();

	token = tokens->head;
	while (token)
	{
		if (string_equal(token->val, "("))
			push_back(stack, token->val, NULL);
		if (string_equal(token->val, ")"))
		{
			if (empty(stack))
			{
				__perror("parse error near token `)'");
				return (-1);
			}
			else
				pop_back(stack);
		}
		token = token->next;
	}
	size_t s = size(stack);
	list_clear(&stack);

	if (s != 0)
	{
		__perror("parse error near token `('");
		return (-1);
	}
	return (0);
}

bool	not_space(t_node *node)
{
	return (node && !string_equal(node->val, " "));
}

bool	is_redir(t_node *node)
{
	return (node && is_redirection(node->val));
}

bool is_wildcard(t_node *node)
{
	// return(__strchr(node->val, '*'));
	return(__strchr(node->val, '*'));
}

bool is_not_wildcard(t_node *node)
{
	// return(__strchr(node->val, '*'));
	return(!string_equal(node->val, "*"));
}
