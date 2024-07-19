/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/20 00:54:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool __is_quote__(char *s)
{
	return list_value_same(s, "\'") || list_value_same(s, "\"");
}

void merge_tokens(t_list *tokens)
{
	if (!tokens || empty(tokens)) return;
	bool open = false;
	t_node *token = tokens->head;

	while (token && token->next)
	{
		t_node *next = token->next;
		if (__is_quote__(token->val) && __is_quote__(token->next->val))
		{
			next = token->next->next;
			pop(tokens, token->next);
			pop(tokens, token);
		}
		token = next;
	}
	
	token = tokens->head;
	while (token)
	{
		t_node *next = token->next;

		if (__is_quote__(token->val))
		{
			if (!open)
			{
				token = token->next;
				t_node *tmp = token->next;
				while (tmp && __is_quote__(tmp->val) == false)
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
