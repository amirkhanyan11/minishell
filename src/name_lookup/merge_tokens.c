/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:17:54 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/19 21:51:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void merge_tokens(t_list *tokens)
{
	if (!tokens || empty(tokens)) return;

	bool open = false;
	t_node *token = tokens->head;

	while (token)
	{
		t_node *next = token->next;

		if (list_value_same(token->val, "\'"))
		{
			if (open && list_value_same(token->next->val, "\'"))
			{
				t_node *prev = token->prev;

				prev->val = __strappend(prev->val, token->next->next->val);

				pop(tokens, token->next->next);
				pop(tokens, token->next);
				pop(tokens, token);

				token = prev;
				next = prev->next;
			}
			open = !open;
		}
		token = next;
	}
}
