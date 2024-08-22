/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:17:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/21 19:11:11 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static void	__exit_nb_wrapper(t_command *cmd, const int status, char *err);

extern int	g_exit_status;

void	__exit__(t_command *cmd)
{
	scoped_string	err;
	t_optional		val;

	err = NULL;
	printf("exit\n");
	list_move_back(cmd->options, cmd->args);
	if (size(cmd->args) >= 1)
	{
		val = __atol_strict(front(cmd->args)->val);
		if (!has_value(&val))
		{
			err = __make_string("exit: ", front(cmd->args)->val,
					": numeric argument required");
			__exit_nb_wrapper(cmd, -1, err);
		}
		else if (size(cmd->args) > 1)
		{
			__perror("exit: too many arguments");
			set_exit_status(1);
		}
		else
			__exit_nb_wrapper(cmd, value_or(&val, -1), err);
	}
	else
		__exit_nb_wrapper(cmd, 0, err);
}

static void	__exit_nb_wrapper(t_command *cmd, const int status, char *err)
{
	if (err)
		__perror(err);
	if (cmd->container->size == 1)
	{
		set_exit_status(status);
		exit(g_exit_status);
	}
}

void	__exit_nb__(const int status, char *err)
{
	set_exit_status(status);
	if (err)
		__perror(err);
	exit(g_exit_status);
}

void	msh_exit(t_command *cmd)
{
	eval_wrapper(cmd, _msh_exit);
}

#pragma GCC diagnostic pop
