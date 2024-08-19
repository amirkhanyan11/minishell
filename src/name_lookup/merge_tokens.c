/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 21:34:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void merge_inside_quotes(t_list *tokens);
static bool is_self_mergeable(t_node *token);
static bool is_mergeable(t_node *token);
static void erase_quotes(t_list *tokens);
static bool is_quote_node(t_node * const node);
static void mark_quoted_tokens(t_shell * shell, t_list *tokens);

void merge_tokens(t_shell *shell, t_list *tokens)
{
	if (!tokens || empty(tokens)) return;

	merge_inside_quotes(tokens);

	mark_quoted_tokens(shell, tokens);

	erase_quotes(tokens);

	t_node *token = front(tokens);

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

void save(t_shell * shell, t_node *address)
{
	char *val = __ptoa((size_t)address);

	set_insert(shell->quoted_tokens, val);

	free(val);
}

static void mark_quoted_tokens(t_shell * shell, t_list *tokens)
{
	if (empty(tokens)) return;

	t_node *left_quote = find_if(front(tokens), back(tokens), is_quote_node);

	if (!left_quote) return;

	while (left_quote)
	{
		t_node *right_quote = find(left_quote->next, back(tokens), left_quote->val, string_equal);
		t_node *token = left_quote->next;

		while (token && token != right_quote)
		{
			save(shell, token);
			token = token->next;
		}

		left_quote = find_if(right_quote->next, back(tokens), is_quote_node);

	}
}

static void erase_quotes(t_list *tokens)
{
	if (empty(tokens)) return;

	t_node *token = find_if(front(tokens), back(tokens), is_quote_node);

	while (token)
	{
		t_node *pair = find(token->next, back(tokens), token->val, string_equal);

		if (!pair) break;

		pop(tokens, token);
		token = find_if(pair->next, back(tokens), is_quote_node);
		pop(tokens, pair);
	}
}

static void merge_inside_quotes(t_list *tokens)
{
	if (!tokens || empty(tokens)) return;


	t_node *token = front(tokens);
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
	return token && token->val && __strlen(token->val) == 1 && __strchr(SELF_MERGEABLE_TOKENS, token->val[0]);
}

static bool is_mergeable(t_node *token)
{
	return (!is_self_mergeable(token) && !string_equal(token->val, " "));
}

static bool is_quote_node(t_node * const node)
{
	return (is_quote(node->val));
}
