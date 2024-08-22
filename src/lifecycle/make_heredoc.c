/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:49:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 19:09:01 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define heredoc_prompt "heredoc> "

t_fd	make_heredoc(char *eof, t_shell *shell, bool is_quoted)
{
	t_fd	fd;
	char	*line;

	if (!eof)
		return (-1);
	fd = open_file(HEREDOC, O_CREAT | O_RDWR);
	line = read_line(heredoc_prompt);
	while (!string_equal(line, eof))
	{
		line = __strappend(line, "\n");
		if (!is_quoted && __strchr(line, '$'))
		{
			line = resolve(line, shell);
		}
		__putstr_fd(line, fd);
		free(line);
		line = read_line(heredoc_prompt);
	}
	free(line);
	close(fd);
	return (open_file(HEREDOC, O_RDONLY));
}
