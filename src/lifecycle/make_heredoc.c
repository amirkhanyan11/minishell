/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:49:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/14 16:48:13 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_fd make_heredoc(char *eof)
{
    if (!eof) return -1;

    t_fd fd = open_file(heredoc, O_CREAT | O_RDWR);

    char *line = readline(">"); // can I lose stdin?

    while (!string_equal(line, eof))
    {
        line = __strappend(line, "\n");
        __putstr_fd(line, fd);
        free(line);
        line = readline(">");
    }
    free(line);
    close(fd);
    return open_file(heredoc, O_RDONLY);
}
