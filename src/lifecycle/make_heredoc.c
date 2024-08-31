/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:49:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/31 22:25:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define HEREDOC_PROMPT "heredoc> "

static t_fd make_heredoc_child(char *eof, t_shell *shell, bool is_quoted);


t_fd	make_heredoc(char *eof, t_shell *shell, bool is_quoted)
{
	pid_t pid = __fork();
	int res = 0;


	if (pid == 0)
	{
		exit(make_heredoc_child(eof, shell, is_quoted));
	}
	waitpid(pid, &res, 0);
	return open_file(HEREDOC, O_RDONLY);
}

static t_fd make_heredoc_child(char *eof, t_shell *shell, bool is_quoted)
{
	t_fd	fd;
	char	*line;

	if (!eof)
		return (-1);
	fd = open_file(HEREDOC, O_CREAT | O_RDWR);
	line = readline(HEREDOC_PROMPT);
	while (!string_equal(line, eof))
	{
		line = __strappend(line, "\n", NULL);
		if (!is_quoted && __strchr(line, '$'))
		{
			line = resolve(line, shell);
		}
		__putstr_fd(line, fd);
		free(line);
		line = readline(HEREDOC_PROMPT);
	}
	free(line);
	close(fd);
	return (0);
}
