/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:17:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/12 22:37:57 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_exit_status;

void __exit__(t_command *cmd)
{
	scoped_string err = NULL;
	printf("exit\n");

	list_move_back(cmd->options, cmd->args);

	if (size(cmd->args) >= 1)
	{
		t_optional val = __atol_strict(cmd->args->head->val);
		if (!has_value(&val))
		{
			err = __make_string("exit: ", cmd->args->head->val, ": numeric argument required");
			__exit_nb__(-1, err);
		}
		if (size(cmd->args) > 1)
		{
			__perror("exit: too many arguments");
			set_exit_status(1);
			return;
		}
		else
			__exit_nb__(value(&val), err);
	}
	__exit_nb__(0, err);
}

void __exit_nb__(const int status, char * err)
{
	set_exit_status(status);
	if (err) __perror(err);
	exit(g_exit_status);
}

void msh_exit(t_command *cmd)
{
	eval_wrapper(cmd, _msh_exit);
}
