/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reslove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:27:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/13 20:44:57 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_exit_status;

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
			size_t k = __strchr_p(s + i + 1, p) - s;

			if (s[i + 1] == '?' || s[i + 1] == '$')
				++k;

			if (is_digit(s[i + 1]))
			{
				k = 2;
			}

			char *prefix = __strdup(s);
			char *postfix = __strdup(s + k);
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
				int pid = __fork();

				if (pid == 0) exit(0);

				_val = __itoa(pid);

				val = _val;
			}

			else if (is_digit(*(s + i + 1)))
			{
				val = "";
			}

			else
				val = get_val(shell->export, s + i + 1);

			s[k] = c;

			if (val)
			{
				i += __strlen(val) - 1;
				prefix = __strappend(prefix, val, s + k);
				free(s);
				s = prefix;
			}

			else
			{
				i = __strlen(prefix) - 1;
				prefix = __strappend(prefix, postfix);
				free(s);
				free(postfix);
				s = prefix;
			}

		}
		i++;
	}

	return s;
}
