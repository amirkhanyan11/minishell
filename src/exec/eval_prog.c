/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:37:44 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:43:31 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

// void __eval_prog__deprecated__(t_fd *pipe, t_command *cmd)
// {
// 	if (NULL == cmd) return;

// 	pid_t pid = __fork();
// 	if (0 == pid)
// 	{
// 		close(pipe[in]);
// 		eval_prog(cmd);
// 	}
// 	// int x = 0;
// 	// waitpid(pid, &x, 0);
// 	// cmd->shell->status = WEXITSTATUS(x);
// }

void eval_prog(t_command *cmd)
{
	eval_wrapper(cmd, _program);
}

void __eval_prog__(t_command *cmd)
{
	if (!cmd) __exit(NULL); // from child

	scoped_list options_copy = make_list_copy_range(cmd->options, NULL);
	push_front(options_copy, cmd->name);

	scoped_list args_copy = make_list_copy_range(cmd->args, NULL);
	list_move_back(args_copy, options_copy);

	scoped_matrix _args = make_matrix_from_list(options_copy);
	scoped_matrix _env  = make_matrix_from_tree(cmd->shell->env);

	execve(cmd->name, _args, _env);
	__exit(NULL);
}

#pragma GCC diagnostic pop
