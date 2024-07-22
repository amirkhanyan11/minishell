/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/22 22:27:41 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool __is_quote__(char *s);
static void merge_consequtive_quotes(t_list *tokens);

void merge_tokens(t_list *tokens)
{
	if (!tokens || empty(tokens)) return;

	bool open = false;

	// merge_consequtive_quotes(tokens);

	// print_list(tokens);
	// return;

	t_node *token = tokens->head;
	while (token)
	{
		t_node *next = token->next;

		if (__is_quote__(token->val))
		{
			string quote_type = __strdup(token->val);
			if (!open)
			{
				token = token->next;
				t_node *tmp = token->next;
				while (tmp && list_value_same(tmp->val, quote_type) == false)
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
	if (list_value_same(val, "\'")) return (s == false);

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
		if (!__is_quote__(token->val))
		{
			token = token->next;
			continue;
		}

		if (list_value_same(token->val, "\'")) s = !s;

		else d = !d;

		t_node *next = token->next;

		if (((s ^ d) && list_value_same(token->next->val, token->val)) || (__is_quote__(token->next->val) && __is_opening__(token->val, s, d)

				&& __is_opening__(token->next->val, s, d)))
		{
			next = token->next->next;
			pop(tokens, token->next);
			pop(tokens, token);
		}
		token = next;
	}
}

static bool __is_quote__(char *s)
{
	return list_value_same(s, "\'") || list_value_same(s, "\"");
}