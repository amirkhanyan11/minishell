/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 00:41:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_shell *shell = make_shell(env);

	while (true)
	{
		char * line = read_line();
		
		t_command *cmd = make_command(line);

		if (0 == __strcmp(cmd->name, "pwd")) pwd(shell);

		else if (0 == __strcmp(cmd->name, "history")) display_history(shell);

		else if (0 == __strcmp(cmd->name, "export")) export(shell);

		if (0 == __strcmp(cmd->name, "exit")) break;

		push_back(shell->history, line);

		__t_command__(cmd);
	}

	print_list(shell->path);

	__t_shell__(&shell);
	return 0;
}
