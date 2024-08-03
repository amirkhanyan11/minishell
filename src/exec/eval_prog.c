/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:37:44 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/03 15:25:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void __eval_prog__(t_command *cmd);

void eval_prog(t_file *pipe, t_cmd_container *cmds, size_t i)
{
	if (NULL == cmds || i >= cmds->size) return;

	t_command *cmd = cmds->arr[i];

	pid_t pid = __fork();
	if (0 == pid)
	{
		close(pipe[in]);
		__eval_prog__(cmd);
	}
	// int x = 0;
	// waitpid(pid, &x, 0);
	// cmd->shell->status = WEXITSTATUS(x);
}

static void __eval_prog__(t_command *cmd)
{
	if (!cmd || cmd_lookup(cmd) == -1) __exit(NULL); // from child

	a_list options_copy = make_list_copy_range(cmd->options, NULL);
	push_front(options_copy, cmd->name);

	a_list args_copy = make_list_copy_range(cmd->args, NULL);
	list_move_back(args_copy, options_copy);

	a_matrix _args = make_matrix_from_list(options_copy);
	a_matrix _env  = make_matrix_from_tree(cmd->shell->env);

	execve(cmd->name, _args, _env);
	__exit(NULL);
}
