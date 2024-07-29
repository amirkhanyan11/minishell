/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:37:44 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 17:19:16 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void eval_prog(t_command *cmd)
{
	int lookup = cmd_lookup(cmd);

	if (lookup == -1) __exit(NULL);

	a_list options_copy = make_list_copy(cmd->options, NULL);
	push_front(options_copy, cmd->name);
	
	a_list args_copy = make_list_copy(cmd->args, NULL);
	list_move_back(args_copy, options_copy);
	
	a_matrix _args = make_matrix_from_list(options_copy);
	a_matrix _env  = make_matrix_from_list(shell->env);
	
	execve(cmd->name, _args, _env);
	__exit(NULL);
}
