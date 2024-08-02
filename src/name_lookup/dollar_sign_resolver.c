/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 21:08:09 by aamirkha         ###   ########.fr       */
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

		if ((!squote_open || dquote_open))
			resolve(token, tokens, shell);

		token = next;
	}
}
