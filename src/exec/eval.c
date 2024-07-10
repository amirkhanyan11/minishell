/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:29:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 19:36:18 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void cmd_lookup(t_command *cmd);

void eval(t_command *cmd, char **env)
{
	cmd_lookup(cmd);

	pid_t pid = __fork();

	if (0 == pid)
	{
		t_list *options_copy __attribute__((cleanup(list_clear))) = make_list_copy(cmd->options, NULL);

		push_front(options_copy, cmd->name);

		t_list *args_copy __attribute__((cleanup(list_clear))) = make_list_copy(cmd->args, NULL);

		list_move_back(args_copy, options_copy);

		t_matrix _args __attribute__((cleanup(__matrix_clear))) = make_matrix_from_list(options_copy);
		t_matrix _env __attribute__((cleanup(__matrix_clear))) = make_matrix_from_list(shell->env);


		execve(cmd->name, _args, _env);
		__exit(strerror(errno));
	}

	wait(NULL);
}


