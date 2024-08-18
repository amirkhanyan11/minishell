/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:59:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void dollar_sign_resolver(t_list *tokens, t_shell *shell)
{
	if (!tokens || !shell) return;

	scoped_list queue = make_list();
	t_node *token = front(tokens);

	while (token)
	{
		t_node *next = token->next;

		if (is_quote(token->val))
		{
			if (empty(queue))
				push_back(queue, token->val);

			else if (string_equal(front(queue)->val, token->val))
				pop_front(queue);
		}

		if ((empty(queue) || string_equal(front(queue)->val, "\"")) && __strchr(token->val, '$'))
		{
			token->val = resolve(token->val, shell);
		}

		token = next;
	}
}
