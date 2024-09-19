/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/19 14:54:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar_sign_resolver(t_list *tokens, t_shell *shell)
{
	t_list	*queue;
	t_node	*token;
	t_node	*next;

	if (!tokens || !shell)
		return ;
	queue = make_list();
	token = tokens->head;
	while (token)
	{
		next = token->next;
		if (is_quote(token->val))
		{
			if (empty(queue))
				push_back(queue, token->val, NULL);
			else if (string_equal(queue->head->val, token->val))
				pop_front(queue);
		}
		if ((empty(queue) || string_equal(queue->head->val, "\""))
			&& __strchr(token->val, '$'))
		{
			if (string_equal(token->val, "$") && token->next && is_opening_parenthesis(token->next->val))
			{
				list_compress(tokens, token, rfind_if(token, tokens->tail, is_closing_parenthesis_node));
				subshell_eval(tokens, token, shell);
				next = token->next;
			}

			else
				token->val = resolve(token->val, shell);
			// if (string_equal(token->val, "$") && token->next && !string_equal(token->next->val, " ")) // echo $""USER
			// 	pop(tokens, token);

		}
		token = next;
	}
	list_clear(&queue);
}
