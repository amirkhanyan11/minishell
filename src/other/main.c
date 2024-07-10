/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 19:53:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

t_shell *shell = NULL;

int main(int ac, char **av, char **env)
{
	shell = make_shell(env);

	// fetch -> decode -> execute
	while (true)
	{
		char * line = read_line();

		t_command * $dtor(__t_command__) cmd = make_command(line, shell);

		if (NULL == cmd) continue;

		if (0 == __strcmp(cmd->name, "pwd")) pwd();

		else if (0 == __strcmp(cmd->name, "history")) display_history();

		else if (0 == __strcmp(cmd->name, "export")) export();

		else if (0 == __strcmp(cmd->name, "echo")) echo(cmd);

		else if (0 == __strcmp(cmd->name, "env")) print_list(shell->env);

		else if (0 == __strcmp(cmd->name, "exit")) break;

		else eval(cmd, env);

		push_back(shell->history, line);

		add_history(line);
	}

	return 0;
}

// #ifdef __APPLE__
// void	__attribute__((destructor)) moid(void)
// {
// 	// printf(GREEN);
// 	printf("\n\nLeaks report\n");
// 	system("leaks minishell");
// 	// printf(RESET);
// }
// #endif // __APPLE__
