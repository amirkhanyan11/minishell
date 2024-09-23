/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:20:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/09/18 21:54:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// pipe parse has to be formatted for || OR operator
//  add & as a special symbol

static void logcmd(const char * line, t_fd logfile)
{
	static size_t x = 1;

	char *out __attribute__((cleanup(__delete_string))) = __itoa((int)x++);

	out = __strappend(out, ". ", line, NULL);

	__putendl_fd(out, logfile);
}

int	main(int ac, char **av, char **env)
{
	t_shell			*shell;
	char			*line;
	t_cmd_container	*cmds;

	if (ac != 2) return -1;

	shell = make_shell(env);
	line = av[1];
	cmds = make_cmd_container(line, shell);
	eval(cmds);

	__t_cmd_container__(&cmds);

	__delete_string(&line);

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