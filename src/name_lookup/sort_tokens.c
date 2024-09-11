/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:54:25 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/31 21:57:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	sort_tokens(t_command *cmd, t_list *tokens)
{
	t_node	*token;

	if (!cmd)
		return (-1);
	token = front(tokens)->next;
	while (token && token->val && token->val[0] == '-')
	{
		push_back(cmd->options, token->val, NULL);
		token = token->next;
	}
	while (token)
	{
		push_back(cmd->args, token->val, NULL);
		token = token->next;
	}
	return (0);
}
