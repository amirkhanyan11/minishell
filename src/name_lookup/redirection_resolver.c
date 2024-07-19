/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 00:32:15 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/20 00:50:16 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int redirection_resolver(t_list *tokens)
{
    t_node *token = tokens->head;
	bool dquote_open = false;
	bool squote_open = false;
    
	while (token)
	{
		t_node *next = token->next;

		if (list_value_same(token->val, "\"")) dquote_open = !dquote_open;

		if (list_value_same(token->val, "\'")) squote_open = !squote_open;

		if ((!squote_open && !dquote_open) && list_value_same(token->val, "<") || list_value_same(token->val, ">") || list_value_same(token->val, ">>")) 
		{
			int redir = redirect(token);

			if (-1 == redir) return -1;

			t_node *next = token->next->next;
			pop(tokens, token->next);
			pop(tokens, token);
			token = next;
			continue;
		}
		token = next;
	}
    return 0;
}