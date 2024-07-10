/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 23:26:08 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void eval(t_command *cmd)
{
	cmd_lookup(cmd);

	pid_t pid = __fork();

	if (0 == pid)
	{
		dup2(shell->descriptors->stdin, STDIN_FILENO);
		dup2(shell->descriptors->stdout, STDOUT_FILENO);

		t_list * __dtor(list_clear) options_copy = make_list_copy(cmd->options, NULL);

		push_front(options_copy, cmd->name);

		t_list * __dtor(list_clear) args_copy = make_list_copy(cmd->args, NULL);

		list_move_back(args_copy, options_copy);

		t_matrix  __dtor(__matrix_clear) _args = make_matrix_from_list(options_copy);
		t_matrix  __dtor(__matrix_clear) _env  = make_matrix_from_list(shell->env);

		execve(cmd->name, _args, _env);
		__exit(strerror(errno));
	}

	// dup2(shell->sysdescriptors->stdin, shell->descriptors->stdin);
	// dup2(shell->sysdescriptors->stdout, shell->descriptors->stdout);

	wait(NULL);
}
