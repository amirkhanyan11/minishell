/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/19 22:02:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell * shell;

// handles redirections and $variables
t_list * __result_use_check preprocess(t_list *tokens)
{
	if (empty(tokens) || !shell) return NULL;

	// merge_tokens(tokens); // segfault

	list_remove(tokens, " ");

	dollar_sign_resolver(tokens);

	print_list(tokens);
	return NULL;

	t_node *token = tokens->head;

	while (token)
	{
		t_node *next = token->next;

		if (0 == __strcmp(token->val, "<") || 0 == __strcmp(token->val, ">") || 0 == __strcmp(token->val, ">>")) // better make a separate function line the dollar_sign_resolver()
		{
			int redir = redirect(token);

			if (-1 == redir) return NULL;

			t_node *next = token->next->next;
			pop(tokens, token->next);
			pop(tokens, token);
			token = next;
			continue;
		}
		token = next;
	}
	return tokens;
}
