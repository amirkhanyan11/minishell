/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 20:12:16 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_shell *shell = make_shell(env);
	t_command *cmd = NULL;

	while (true)
	{
		char * line = read_line();

		cmd = make_command(line);

		if (0 == __strcmp(cmd->name, "pwd")) pwd(shell);

		else if (0 == __strcmp(cmd->name, "history")) display_history(shell);

		else if (0 == __strcmp(cmd->name, "export")) print_list(shell->export);

		else if (0 == __strcmp(cmd->name, "env") || 0 == __strcmp(cmd->name, "printenv")) print_list(shell->env);

		else if (0 == __strcmp(cmd->name, "exit")) break;

		push_back(shell->history, line);

		__t_command__(&cmd);
	}

	__t_command__(&cmd);
	__t_shell__(&shell);

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
