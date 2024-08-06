/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 18:53:50 by aamirkha         ###   ########.fr       */
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
		scoped_string line = read_line();

		a_cmd_container cmds = make_cmd_container(line, shell);

		if (!line) // && cmds->arr[0] && string_equal(cmds->arr[0]->name, "exit"))
		{
			printf("exit\n");
			break;
		}

		eval(cmds);

		if (__strcmp(line, "\n"))
		{
			push_back(shell->history, line);

			add_history(line);
		}

	}
	__t_shell__(shell);

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
