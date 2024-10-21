/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:17:06 by marikhac          #+#    #+#             */
/*   Updated: 2024/10/10 22:02:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	__exit_nb__(t_cmd *cmd, const int status, char *err);
static void	foo(char **err, t_cmd *cmd);
static void	moo(void);

void	msh_exit(t_cmd *cmd)
{
	char		*err;
	t_optional	val;

	if (!cmd->forkable)
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
			moo();
		else
			__exit_nb__(cmd, value_or(&val, -1), err);
	}
	else
		__exit_nb__(cmd, get_exit_status(), err);
	__delete_string(&err);
}

static void	moo(void)
{
	__perror("exit: too many arguments");
	set_exit_status(1);
}

static void	foo(char **err, t_cmd *cmd)
{
	*err = __make_string("exit: ", front(cmd->args)->val,
			": numeric argument required", NULL);
}

static void	__exit_nb__(t_cmd *cmd, const int status, char *err)
{
	if (err)
		__perror(err);
	set_exit_status(status);
	__delete_string(&err);
	__t_shell__(cmd->shell);
	exit(get_exit_status());
}
