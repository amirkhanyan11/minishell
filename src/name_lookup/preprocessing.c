/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/16 20:04:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles redirections and $variables
t_list	*preprocess(t_list *tokens, t_shell *shell)
{
	if (empty(tokens) || !shell)
		return (NULL);
	dollar_sign_resolver(tokens, shell);
	merge_tokens(shell, tokens);
	if (pipe_parse(tokens, shell) == -1 || redirection_parse(tokens, shell) == -1)
	{
		set_exit_status_no_of(258);
		list_clear(&tokens);
		return (tokens);
	}
	remove_spaces(shell, tokens);
	wildcard_resolve(tokens, shell);
	return (tokens);
}

bool	is_quoted_token(t_set *set, t_node *token)
{
	char *guess	__attribute__((cleanup(__delete_string)));

	if (!set || !token)
		return (false);
	guess = __ptoa((size_t)token);
	return (set_count(set, guess) != 0);
}

void	remove_spaces(t_shell *shell, t_list *tokens)
{
	t_node	*curr;
	t_node	*next;

	if (!shell || empty(tokens))
		return ;
	curr = front(tokens);
	while (curr)
	{
		next = curr->next;
		if (string_equal(curr->val, " ")
			&& !is_quoted_token(shell->quoted_tokens, curr))
		{
			pop(tokens, curr);
		}
		curr = next;
	}
}
