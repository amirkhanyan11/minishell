/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reslove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:27:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 19:36:34 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_exit_status;

static char *get_pid(t_shell *shell) __result_use_check;

static bool p(char c)
{
	return !is_name_part(c);
}

char *resolve(char *t_val, t_shell *shell)
{
	size_t i = 0;
	char *s = __strdup(t_val);

	while (s[i] && s[i + 1])
	{
		if (s[i] == '$')
		{
			size_t k = __strchr_p(s + i + 1, p) - s; // k - i + 1 is the length of the name of the variable

			if (s[i + 1] == '?' || s[i + 1] == '$')
				++k;

			if (is_digit(s[i + 1]))
			{
				k = 2;
			}

			char *prefix = __strdup(s);
			scoped_string postfix = __strdup(s + k);
			prefix[i] = '\0';


			char c = s[k];
			s[k] = '\0';

			char *val = NULL;
			scoped_string _val = NULL;

			if (string_equal(s + i, "$?"))
			{
				_val = __itoa(g_exit_status);

				val = _val;
			}

			else if (string_equal(s + i, "$$"))
			{
				_val = get_pid(shell);
				val = _val;
			}

			else if (is_digit(*(s + i + 1)))
			{
				val = "";
			}

			else
				val = get_val(shell->export, s + i + 1);

			s[k] = c;

			if (!val) val = postfix;

			i += __strlen(val) - 1;
			prefix = __strappend(prefix, val, s + k);
			free(s);
			s = prefix;

		}
		i++;
	}
	free(t_val);
	return s;
}


static char *get_pid(t_shell *shell)
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
