/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/03 17:04:15 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void dollar_sign_resolver(t_list *tokens, t_shell *shell)
{
	if (!tokens || !shell) return;

	bool dquote_open = false;
	bool squote_open = false;
	t_node *token = tokens->head;

	while (token)
	{
		t_node *next = token->next;

		if (list_value_same(token->val, "\"")) dquote_open = !dquote_open;

		if (list_value_same(token->val, "\'")) squote_open = !squote_open;

		if ((!squote_open || dquote_open)) // echo '"$SHELL"' resolves, which shouldn't
			resolve(token, tokens, shell);

		token = next;
	}
}
