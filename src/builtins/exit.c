/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:17:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/09 19:24:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_exit_status;

void __exit__(t_command *cmd)
{
	scoped_string err = NULL;

	list_move_back(cmd->options, cmd->args);

	if (size(cmd->args) > 1)
	{
		__perror("exit: too many arguments");
		set_exit_status(1);
		return;
	}
	else if (size(cmd->args) == 1)
	{
		t_optional val = __atoi_strict(cmd->args->head->val);
		if (!has_value(&val))
		{
			err = __make_string("exit: ", cmd->args->head->val, ": numeric argument required");
			set_exit_status(-1);
		}
		else set_exit_status(value(&val));
	}
	else
		set_exit_status(0);
	printf("exit\n");
	if (err) __perror(err);
	exit(g_exit_status);
}

void msh_exit(t_command *cmd)
{
	eval_wrapper(cmd, _msh_exit);
}
