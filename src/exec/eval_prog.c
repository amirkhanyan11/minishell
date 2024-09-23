/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:37:44 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/23 15:25:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void	eval_prog(t_cmd *cmd)
{
	eval_wrapper(cmd, _program);
}
void	__eval_prog__(t_cmd *cmd)
{
	t_list		*options_copy;
	t_list		*args_copy;
	t_matrix	_args;
	t_matrix	_env;

	if (!cmd)
		__exit(NULL);
	options_copy = make_list_copy_range(cmd->options, NULL);
	push_front(options_copy, cmd->name, NULL);

	args_copy = make_list_copy_range(cmd->args, NULL);
	list_move_back(args_copy, options_copy);
	_args = make_matrix_from_list(options_copy);
	_env = make_matrix_from_tree(cmd->shell->env);

	execve(cmd->name, _args, _env);
	__t_shell__(cmd->shell);
	__exit(NULL);
}

#pragma GCC diagnostic pop
