/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:09:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 18:47:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void unset(t_command *cmd)
{
	eval_wrapper(cmd, _unset);
}

void unset_var(t_shell *shell, t_list_value key)
{
	if (!key) return;

	tree_pop(shell->export, key);
	tree_pop(shell->env, key);
}


void __unset__(t_command *cmd)
{
	if (!cmd || !cmd->args) return;

	t_node *arg = cmd->args->head;

	while (arg)
	{
		unset_var(cmd->shell, arg->val);
		arg = arg->next;
	}
}
