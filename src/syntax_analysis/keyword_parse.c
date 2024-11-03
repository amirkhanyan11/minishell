/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:22:42 by aamirkha          #+#    #+#             */
/*   Updated: 2024/11/03 16:27:43 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	kwd_parse_error(char *token)
{
	__va_perror("parse error near token `", token, "\'", NULL);
	return (false);
}

bool	keyword_parse(t_list *tokens, t_shell *shell)
{
	t_listnode	*token;
	t_listnode	*pair;

	token = shfind_if(tokens->head, tokens->tail, is_binary_operator, shell);
	if (token == tokens->head)
	{
		if (token)
			kwd_parse_error(token->val);
		return (false);
	}
	while (token)
	{
		pair = shfind_if(token->next, tokens->tail, is_binary_operator, shell);
		if (!pair)
			pair = tokens->tail;
		else
			pair = pair->prev;
		if (NULL == shfind_if(token->next, pair,
				not_binary_operator_nor_parenthesis, shell))
		{
			return (kwd_parse_error(token->val));
		}
		token = shfind_if(pair->next, tokens->tail, is_binary_operator, shell);
	}
	return (true);
}
