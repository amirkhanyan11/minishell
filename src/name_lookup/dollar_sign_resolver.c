/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/03 18:01:03 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void dollar_sign_resolver(t_list *tokens, t_shell *shell)
{
	if (!tokens || !shell) return;

	a_list queue = make_list();
	t_node *token = tokens->head;

	while (token)
	{
		t_node *next = token->next;

		if (is_quote(token->val))
		{

			if (empty(queue) || !string_equal(queue->tail->val, token->val))
				push_back(queue, token->val);

			else
				pop_back(queue);
		}

		if (empty(queue) || string_equal(queue->head->val, "\""))
			resolve(token, tokens, shell);

		token = next;
	}
}
