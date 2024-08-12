/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:09:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/12 19:36:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void unset(t_command *cmd)
{
	eval_wrapper(cmd, _unset);
}

int unset_var(t_shell *shell, t_list_value key)
{
	if (!key) return -1;

	if(!is_name(key))
	{
		scoped_string str = __make_string("unset: `", key, "\': not a valid identifier");
		__perror(str);
		return (-1);
	}

	tree_remove(shell->export, key);
	tree_remove(shell->env, key);
	return (0);
}


void __unset__(t_command *cmd)
{
	if (!cmd || !cmd->args) return;

	int status = 0;
	t_node *arg = cmd->args->head;

//  unset: -a: invalid option
	
	if(!empty(cmd->options))
	{
		scoped_string str = __make_string("unset: ", cmd->options->head->val, ": invalid option");
		__perror(str);
		status = 1;
	}
	else
	{
		while (arg)
		{
			if (-1 == unset_var(cmd->shell, arg->val))
				status = 1;
			arg = arg->next;
		}
	}
	set_exit_status(status);
}
