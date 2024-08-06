/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:09:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:46:00 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void __unset__(t_shell *shell, t_list_value key)
{
	if (!key) return;

	tree_pop(shell->export, key);
	tree_pop(shell->env, key);
}


void unset(t_command *cmd)
{
	if (!cmd || !cmd->args) return;

	t_node *arg = cmd->args->head;

	while (arg)
	{
		__unset__(cmd->shell, arg->val);
		arg = arg->next;
	}
}
