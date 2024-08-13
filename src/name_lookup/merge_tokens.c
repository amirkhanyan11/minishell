/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/13 18:31:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void merge_inside_quotes(t_list *tokens);
static bool is_self_mergeable(t_node *token);
static bool is_mergeable(t_node *token);
static void erase_quotes(t_list *tokens);
static bool is_quote_node(t_node * const node);


void merge_tokens(t_list *tokens)
{
	if (!tokens || empty(tokens)) return;

	merge_inside_quotes(tokens);

	erase_quotes(tokens);

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

static void erase_quotes(t_list *tokens)
{
	if (empty(tokens)) return;

	t_node *token = find_if(tokens->head, tokens->tail, is_quote_node);

	while (token)
	{
		t_node *pair = find(token->next, tokens->tail, token->val, string_equal);

		if (!pair) break;

		pop(tokens, token);
		token = find_if(pair->next, tokens->tail, is_quote_node);
		pop(tokens, pair);
	}
}

static void merge_inside_quotes(t_list *tokens)
{
	if (!tokens || empty(tokens)) return;


	t_node *token = tokens->head;
	while (token)
	{
		t_node *next = token->next;

		if (is_quote(token->val))
		{
			scoped_string quote_type = __strdup(token->val);

			if (token->next && string_equal(token->next->val, quote_type))
			{
				list_insert(tokens, token, "");
				next = token->next;
			}

			token = token->next;
			t_node *tmp = token->next;

			while (tmp && string_equal(tmp->val, quote_type) == false)
			{
				next = tmp->next;
				token->val = __strappend(token->val, tmp->val);
				pop(tokens, tmp);
				tmp = next;
			}
			if (tmp) tmp = tmp->next;
			next = tmp;
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

static bool is_quote_node(t_node * const node)
{
	return (is_quote(node->val));
}
