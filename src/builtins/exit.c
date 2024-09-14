/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:17:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/09/14 23:39:23 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static void	__exit_nb__(t_command *cmd, const int status, char *err);
static void	foo(char **err, t_command *cmd);

void	__exit__(t_command *cmd)
{
	char		*err;
	t_optional	val;

	printf("exit\n");
	err = NULL;
	list_move_back(cmd->options, cmd->args);
	if (size(cmd->args) >= 1)
	{
		val = __atol_strict(front(cmd->args)->val);
		if (!has_value(&val))
		{
			foo(&err, cmd);
			__exit_nb__(cmd, -1, err);
		}
		else if (size(cmd->args) > 1)
		{
			__perror("exit: too many arguments");
			set_exit_status(1);
		}
		else
			__exit_nb__(cmd, value_or(&val, -1), err);
	}
	else
		__exit_nb__(cmd, get_exit_status(), err);
	__delete_string(&err);
}

static void	foo(char **err, t_command *cmd)
{
	*err = __make_string("exit: ", front(cmd->args)->val,
			": numeric argument required", NULL);
}

static void	__exit_nb__(t_command *cmd, const int status, char *err)
{
	if (err)
		__perror(err);
	if (cmd->container->size == 1)
	{
		set_exit_status(status);
		__delete_string(&err);
		t_shell *shell = cmd->shell;
		__t_cmd_container__(&cmd->container);
		__t_shell__(shell);
		exit(get_exit_status());
	}
}

void	msh_exit(t_command *cmd)
{
	eval_wrapper(cmd, _msh_exit);
}

#pragma GCC diagnostic pop
