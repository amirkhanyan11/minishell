/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reslove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:27:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 16:55:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

static bool p(char c)
{
	return !is_name_part(c);
}

void resolve(t_node *t, t_list *tokens) // add $?
{
	size_t i = 0;
	char *s = __strdup(t->val);

	while (s[i] && s[i + 1])
	{
		if (s[i] == '$')
		{
			size_t k = __strchr_p(s + i + 1, p) - s;
			char *prefix = __strdup(s);
			char *postfix = __strdup(s + k);
			prefix[i] = '\0';

			char c = s[k];
			s[k] = '\0';

			string val = get_value(shell->export, s + i + 1);
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

	free(t->val);
	t->val = s;
}
