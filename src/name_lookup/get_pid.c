/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:45:58 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/22 17:46:18 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_pid(t_shell *shell)
{
	t_fd pipe[PIPE_MAX];

	char *val = NULL;

	__pipe(pipe);
	t_fd pid = __fork();
	if (pid == 0)
	{
		char *cmd[] = {"/bin/ps", NULL};
		scoped_matrix t_env = make_matrix_from_tree(shell->env);
		dup2(pipe[out], STDOUT_FILENO);
		close(pipe[in]);
		execve(cmd[0], cmd, t_env);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);

	val = get_next_line(pipe[in]);

	while (val && !__strstr(val, "minishell"))
	{
		free(val);
		val = get_next_line(pipe[in]);
	}

	get_next_line(-1);

	if (!val) val = __strdup("1337");

	t_optional p = __atoi(val);

	free(val);
	val = __itoa(value(&p));

	close(pipe[in]);
	close(pipe[out]);

	return val;
}
