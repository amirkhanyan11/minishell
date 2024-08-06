/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 20:49:59 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void merge_inside_quotes(t_list *tokens);

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

		if ((__strlen(token->val) == 1 && !strchr(non_mergeable_tokens, token->val[0]) && string_equal(next->val, token->val)) || (!string_equal(token->val, " ") && !string_equal(next->val, " ")))
		{
			token->val = __strappend(token->val, next->val);
			pop(tokens, next);
			next = token;
		}
		token = next;
	}
}

void merge_inside_quotes(t_list *tokens)
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

static bool __is_opening__(t_list_value val, bool s, bool d)
{
	if (string_equal(val, "\'")) return (s == false);

	else return (d == false);
}

static void merge_consequtive_quotes(t_list *tokens)
{
	if (!tokens || empty(tokens)) return;

	bool s = false;
	bool d = false;

	t_node *token = tokens->head;

	while (token && token->next)
	{
		if (!is_quote(token->val))
		{
			token = token->next;
			continue;
		}

		if (string_equal(token->val, "\'")) s = !s;

		else d = !d;

		t_node *next = token->next;

		if (((s ^ d) && string_equal(token->next->val, token->val)) || (is_quote(token->next->val) && __is_opening__(token->val, s, d)

				&& __is_opening__(token->next->val, s, d)))
		{
			next = token->next->next;
			pop(tokens, token->next);
			pop(tokens, token);
		}
		token = next;
	}
}

