/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 20:38:56 by aamirkha         ###   ########.fr       */
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
		string line = read_line();
		// char * line = av[1];

		a_cmd_container cmds = make_cmd_container(line);

		if (NULL != cmds)
		{
			if (cmds->size == 1 && list_value_same(cmds->arr[0]->name, "exit")) break;

			size_t i = 0;
			
			while (i < cmds->size)
			{
				eval(cmds, i++);
			}
			while (-1 != wait(NULL));
		}

		if (line && *line && __strcmp(line, "\n"))
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
