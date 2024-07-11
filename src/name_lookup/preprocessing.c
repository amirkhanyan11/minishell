/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 18:14:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell * shell;

// handles redirections and $variables
t_list * __result_use_check preprocess(t_list *tokens)
{
	if (!tokens || !shell) __exit("bad preprocessor values");

	t_node *token = tokens->head;

	dollar_sign_resolver(tokens);

	while (token)
	{
		t_node *next = token->next;


		if (0 == __strcmp(token->val, "<") || 0 == __strcmp(token->val, ">")) // better make a separate function line the dollar_sign_resolver()
		{
			int redir = redirect(token);
			if (-1 == redir) return NULL;
			t_node *next = token->next->next;
			list_remove(tokens, token->next);
			list_remove(tokens, token);
			token = next;
			continue;
		}
		token = next;
	}
	return tokens;
}
