/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/07 17:14:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void merge_inside_quotes(t_list *tokens);
static bool is_self_mergeable(t_node *token);
static bool is_mergeable(t_node *token);

void merge_tokens(t_list *tokens)
{
	if (!tokens || empty(tokens)) return;

	merge_inside_quotes(tokens);

	list_remove(tokens, "\'");
	list_remove(tokens, "\"");

	t_node *token = tokens->head;

	while (token && token->next)
	{
		t_node *next = token->next;

		if (string_equal(token->val, "<<") || string_equal(token->val, ">>"))
		{
			token = next;
			continue;
		}

		if ((is_self_mergeable(token) && string_equal(next->val, token->val)) || (is_mergeable(token) && is_mergeable(next)))
		{
			token->val = __strappend(token->val, next->val);
			pop(tokens, next);
			next = token;
		}

		token = next;
	}
}

static void merge_inside_quotes(t_list *tokens)
{
	if (!tokens || empty(tokens)) return;

	bool open = false;

	t_node *token = tokens->head;
	while (token)
	{
		t_node *next = token->next;

		if (is_quote(token->val))
		{
			scoped_string quote_type = __strdup(token->val);
			if (!open)
			{
				token = token->next;
				t_node *tmp = token->next;
				while (tmp && string_equal(tmp->val, quote_type) == false)
				{
					next = tmp->next;
					token->val = __strappend(token->val, tmp->val);
					pop(tokens, tmp);
					tmp = next;
				}
				next = tmp;
			}
			open = !open;
		}
		token = next;
	}
}


static bool is_self_mergeable(t_node *token)
{
	return token && token->val && __strlen(token->val) == 1 && strchr(self_mergeable_tokens, token->val[0]);
}

static bool is_mergeable(t_node *token)
{
	return (!is_self_mergeable(token) && !string_equal(token->val, " "));
}
