/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/09 15:40:32 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// pipe parse has to be formatted for || OR operator
//  add & as a special symbol

int	main(int ac, char **av, char **env)
{
	t_shell			*shell;
	char			*line;
	t_cmd_container	*cmds;

	shell = make_shell(env);
	while (true)
	{
		line = read_line(MINISHELL_PROMPT);
		cmds = make_cmd_container(line, shell);
		if (!line)
		{
			__exit_nb__(0, NULL);
		}
		eval(cmds);
		if (__strlen(line) > 0)
		{
			push_back(shell->history, line, NULL);
			add_history(line);
		}
		__delete_string(&line);
		__t_cmd_container__(&cmds);
	}
	__t_shell__(shell);
	return (get_exit_status());
}

#ifdef __APPLE__
void	__attribute__((destructor)) moid(void)
{
	// printf(GREEN);
	printf("\n\nLeaks report\n");
	system("leaks minishell");
	// printf(RESET);
}
#endif // __APPLE__
