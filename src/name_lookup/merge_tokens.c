/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 15:45:32 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	merge_inside_quotes(t_list *tokens);
static bool	is_self_mergeable(t_node *token);
static bool	is_mergeable(t_node *token);

static void	merge_inside_quotes_the_good_part(t_list *tokens, t_node **t,
				t_node **next);

void	merge_tokens(t_shell *shell, t_list *tokens)
{
	t_node	*token;
	t_node	*next;

	if (!tokens || empty(tokens))
		return ;
	merge_inside_quotes(tokens);
	mark_quoted_tokens(shell, tokens);
	token = front(tokens);
	while (token && token->next)
	{
		next = token->next;
		if (string_equal(token->val, "<<") || string_equal(token->val, ">>"))
		{
			token = next;
			continue ;
		}
		if ((is_self_mergeable(token) && string_equal(next->val, token->val))
			|| (is_mergeable(token) && is_mergeable(next)))
		{
			token->val = __strappend(token->val, next->val);
			pop(tokens, next);
			next = token;
		}
		token = next;
	}
}

static void	merge_inside_quotes(t_list *tokens)
{
	t_node	*token;
	t_node	*next;

	if (!tokens || empty(tokens))
		return ;
	token = front(tokens);
	while (token)
	{
		next = token->next;
		if (is_quote(token->val))
		{
			merge_inside_quotes_the_good_part(tokens, &token, &next);
		}
		token = next;
	}
}

static void	merge_inside_quotes_the_good_part(t_list *tokens, t_node **t,
		t_node **next)
{
	t_node	*tmp;
	char	*quote_type;

	quote_type = __strdup((*t)->val);
	if ((*t)->next && string_equal((*t)->next->val, quote_type))
	{
		list_insert(tokens, (*t), "");
		(*next) = (*t)->next;
	}
	(*t) = (*t)->next;
	tmp = (*t)->next;
	while (tmp && string_equal(tmp->val, quote_type) == false)
	{
		(*next) = tmp->next;
		(*t)->val = __strappend((*t)->val, tmp->val);
		pop(tokens, tmp);
		tmp = (*next);
	}
	if (tmp)
		tmp = tmp->next;
	(*next) = tmp;
	__delete_string(&quote_type);
}

static bool	is_self_mergeable(t_node *token)
{
	return (token && token->val && __strlen(token->val) == 1
		&& __strchr(SELF_MERGEABLE_TOKENS, token->val[0]));
}

static bool	is_mergeable(t_node *token)
{
	return (!is_self_mergeable(token) && !string_equal(token->val, " "));
}
