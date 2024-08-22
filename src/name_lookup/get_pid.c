/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:45:58 by marikhac          #+#    #+#             */
/*   Updated: 2024/08/22 20:18:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_ps(t_fd *pipe, t_shell *shell);

char	*get_pid(t_shell *shell)
{
	t_fd		pipe[PIPE_MAX];
	char		*val;
	t_optional	p;

	val = NULL;
	__pipe(pipe);
	exec_ps(pipe, shell);
	val = get_next_line(pipe[in]);
	while (val && !__strstr(val, "minishell"))
	{
		free(val);
		val = get_next_line(pipe[in]);
	}
	get_next_line(-1);
	if (!val)
		val = __strdup("1337");
	p = __atoi(val);
	free(val);
	val = __itoa(value(&p));
	close(pipe[in]);
	close(pipe[out]);
	return (val);
}

static void	exec_ps(t_fd *pipe, t_shell *shell)
{
	t_fd		pid;
	t_matrix	t_env;
	char		*cmd[2];

	cmd[0] = "/bin/ps";
	cmd[1] = NULL;
	t_env = NULL;
	pid = __fork();
	if (pid == 0)
	{
		t_env = make_matrix_from_tree(shell->env);
		dup2(pipe[out], STDOUT_FILENO);
		close(pipe[in]);
		execve(cmd[0], cmd, t_env);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
	matrix_clear(&t_env);
}
