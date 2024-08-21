/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/21 18:45:46 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_exit_status;

// handles redirections and $variables
t_list *preprocess(t_list *tokens, t_shell *shell)
{
	if (empty(tokens) || !shell) return NULL;

	dollar_sign_resolver(tokens, shell);

	merge_tokens(shell, tokens);

	if (pipe_parse(tokens) == -1 || redirection_parse(tokens) == -1)
	{
		g_exit_status = 258;
		list_clear(&tokens);
	}

	remove_spaces(shell, tokens); // remove white spaces

	return tokens;
}

bool is_quoted_token(t_set *set, t_node *token)
{
	if (!set || !token) return false;

	scoped_string guess = __ptoa((size_t)token);

	return set_count(set, guess) != 0;
}

void remove_spaces(t_shell *shell, t_list *tokens)
{
	if (!shell || empty(tokens)) return;

	t_node *curr = front(tokens);

	while (curr)
	{
		t_node *next = curr->next;

		if (string_equal(curr->val, " ") && !is_quoted_token(shell->quoted_tokens, curr))
		{
			pop(tokens, curr);
		}

		curr = next;
	}
}
