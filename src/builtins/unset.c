/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:09:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 01:39:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void __unset__(t_shell *shell, t_list_value val)
{
	if (!val) return;

	list_remove_if(shell->export, val, __contains_as_key__);
	list_remove_if(shell->env, val, __contains_as_key__);

	if (list_value_same(val, "PATH")) list_clear(&shell->path); // path is a special case, since I keep it as a separate list
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
