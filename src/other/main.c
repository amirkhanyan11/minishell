/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 19:27:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// different exit status
// <<
// .

int g_exit_status = 0;

int main(int ac, char **av, char **env)
{
	t_shell *shell = make_shell(env);

	// fetch -> decode -> execute
	while (true)
	{
		scoped_string line = read_line(minishell_prompt);

		scoped_cmd_container cmds = make_cmd_container(line, shell);

		if (!line) // ctr + D
		{
			__exit_nb__(0, NULL);
		}

		eval(cmds);

		if (__strlen(line) > 0)
		{
			push_back(shell->history, line);
			add_history(line);
		}

	}
	__t_shell__(shell);

	return g_exit_status;
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
