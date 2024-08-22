/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:37:44 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 19:14:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	eval_prog(t_command *cmd)
{
	eval_wrapper(cmd, _program);
}

void	__eval_prog__(t_command *cmd)
{
	scoped_list		options_copy;
	scoped_list		args_copy;
	scoped_matrix	_args;
	scoped_matrix	_env;

	if (!cmd)
		__exit(NULL); // from child
	options_copy = make_list_copy_range(cmd->options, NULL);
	push_front(options_copy, cmd->name);
	args_copy = make_list_copy_range(cmd->args, NULL);
	list_move_back(args_copy, options_copy);
	_args = make_matrix_from_list(options_copy);
	_env = make_matrix_from_tree(cmd->shell->env);
	execve(cmd->name, _args, _env);
	__exit(NULL);
}

#pragma GCC diagnostic pop
