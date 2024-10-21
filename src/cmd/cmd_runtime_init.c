/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_runtime_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:39:00 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/11 10:20:43 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_runtime_init(t_cmd *cmd)
{
	wildcard_resolve(cmd->tokens, cmd->shell);
	cmd->name = __strdup(cmd->tokens->head->val);
	cmd->orig_name = __strdup(cmd->tokens->head->val);
	if (empty(cmd->tokens) || sort_tokens(cmd, cmd->tokens) == -1
		|| cmd_lookup(cmd) == -1)
	{
		cmd->eval = errcmd;
		cmd->invokable = false;
	}
}
