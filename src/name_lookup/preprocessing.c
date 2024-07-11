/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:21:34 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 17:13:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list * __result_use_check preprocess(t_list *tokens, t_shell * shell)
{
	if (!tokens || !shell) __exit("bad preprocessor values");

	t_node *token = tokens->head;

	while (token)
	{
		if (token->val[0] == '$')
		{
			t_node *next = token->next;
			resolve(token, tokens);
			token = next;
			continue;
		}
		if (0 == __strcmp(token->val, "<") || 0 == __strcmp(token->val, ">"))
		{
			redirect(token);
			t_node *next = token->next->next;
			list_remove(tokens, token->next);
			list_remove(tokens, token);
			token = next;
			continue;
		}
		token = token->next;
	}
	return tokens;
}
