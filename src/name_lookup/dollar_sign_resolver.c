/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 15:09:42 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar_sign_resolver(t_list *tokens, t_shell *shell)
{
	scoped_list	queue;
	t_node		*token;
	t_node		*next;

	queue = NULL;
	if (!tokens || !shell)
		return ;
	queue = make_list();
	token = front(tokens);
	while (token)
	{
		next = token->next;
		if (is_quote(token->val))
		{
			if (empty(queue))
				push_back(queue, token->val);
			else if (string_equal(front(queue)->val, token->val))
				pop_front(queue);
		}
		if ((empty(queue) || string_equal(front(queue)->val, "\""))
					&& __strchr(token->val, '$'))
			token->val = resolve(token->val, shell);
		token = next;
	}
}
