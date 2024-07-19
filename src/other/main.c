/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/19 19:01:44 by aamirkha         ###   ########.fr       */
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

		t_command * __dtor(__t_command__) cmd = make_command(line);

		if (NULL != cmd)
		{
			// printf("name : %s\n\n", cmd->name);
			// printf("args : %zu\n", size(cmd->args));
			// printf("options : %zu\n", size(cmd->options));

			if (0 == __strcmp(cmd->name, "pwd")) pwd();

			else if (0 == __strcmp(cmd->name, "history")) display_history();

			else if (0 == __strcmp(cmd->name, "export")) export(cmd);

			else if (0 == __strcmp(cmd->name, "echo")) echo(cmd);

			else if (0 == __strcmp(cmd->name, "unset")) unset(cmd);

			else if (0 == __strcmp(cmd->name, "env") || 0 == __strcmp(cmd->name, "printenv")) _env(cmd->name);

			else if (0 == __strcmp(cmd->name, "cd")) cd(cmd);

			else if (0 == __strcmp(cmd->name, "exit")) break;

			else eval(cmd);
		}

		if (line && *line && __strcmp(line, "\n"))
		{
			push_back(shell->history, line);

			add_history(line);
		}
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
