/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_resolver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:55 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 18:16:03 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void dollar_sign_resolver(t_list *tokens)
{
	if (!tokens) return;

	t_node *token = tokens->head;

	while (token)
	{
		t_node *next = token->next;

		if (token->val[0] == '$')
			resolve(token, tokens);

		token = next;
	}
}
