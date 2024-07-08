/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 22:15:56 by aamirkha         ###   ########.fr       */
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

		if (0 == __strcmp(line, "pwd")) pwd(shell);

		else if (0 == __strcmp(line, "history")) display_history(shell);

		else if (0 == __strcmp(line, "export")) export(shell);

		else if (0 == __strcmp(line, "exit")) break;

		push_back(shell->history, line);
	}

	printf("%zu\n", accumulate(shell->env, 0, accumulate_by_length));

	__t_shell__(&shell);
	return 0;
}
