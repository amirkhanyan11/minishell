/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:54:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/11/03 16:46:32 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sort_tokens(t_cmd *cmd, t_list *tokens)
{
	t_listnode	*token;

	if (!cmd)
		return (-1);
	token = tokens->head->next;
	if (!token)
		return (0);
	while (token && __str_starts_with(token->val, "-")
		&& !find_addr(cmd->shell->quoted_tokens, token))
	{
		push_back(cmd->options, token->val);
		token = token->next;
	}
	while (token)
	{
		push_back(cmd->args, token->val);
		token = token->next;
	}
	return (0);
}
