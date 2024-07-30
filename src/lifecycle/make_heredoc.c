/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:49:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 03:34:50 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file make_heredoc(char *eof)
{
    if (!eof) return -1;
    
    t_file fd = open_file(heredoc, O_CREAT | O_RDWR);

    char *line = readline(">"); // can I lose stdin?

    while (0 != __strcmp(line, eof))
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