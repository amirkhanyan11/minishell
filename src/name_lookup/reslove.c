/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reslove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:27:27 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/25 17:39:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void resolve(t_node *t, t_list *tokens)
{
	size_t i = 0;
	char *s = __strdup(t->val);

	while (s[i] && s[i + 1])
	{	
		if (s[i] == '$')
		{
			size_t k = __strlen(s);
			while (i < k)
			{
				char c = s[k];
				s[k] = '\0';
					
				string val = get_value(shell->export, s + i + 1);								
				s[k] = c;
				
				if (val)
				{
					char * prefix = __strdup(s);
					prefix[i] = '\0';
					i += __strlen(val) - 1;
					char *tmp = __strappend(prefix, val, s + k);
					free(s);
					s = tmp;
					break;
				}
				
				k--;
			}	
		}
		i++;
	}

	free(t->val);
	t->val = s;
}
