/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:49:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/15 17:46:18 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

# define heredoc_prompt "heredoc> "

t_fd make_heredoc(char *eof, t_shell *shell) // cat << "EOL"
{
    if (!eof) return -1;

    t_fd fd = open_file(heredoc, O_CREAT | O_RDWR);

    char *line = read_line(heredoc_prompt); // can I lose stdin?

    while (!string_equal(line, eof))
    {
        line = __strappend(line, "\n");
		if (__strchr(line, '$'))
		{
			line = resolve(line, shell);
		}
        __putstr_fd(line, fd);
        free(line);
        line = read_line(heredoc_prompt);
    }
    free(line);
    close(fd);
    return open_file(heredoc, O_RDONLY);
}
