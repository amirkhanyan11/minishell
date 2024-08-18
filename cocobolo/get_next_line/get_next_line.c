/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 21:51:37 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <cocobolo.h>

static char	*_____death(char **memory)
{
	__delete_string(memory);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (_____death(&memory));
	if (!memory)
	{
		memory = malloc(1);
		if (!memory)
			return (NULL);
		memory[0] = '\0';
	}
	else
	{
		newline = ft_frankenstein(memory, '\n', __strchr_enum__);
		if (newline)
			ft_mutate(&memory, newline + 1);
		else
		{
			free(memory);
			return ((memory = NULL));
		}
	}
	ft_read(fd, &memory);
	return (ft_fetch(&memory));
}

char	*get_next_line_no_nl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		line[__strlen(line) - 1] = '\0';
	}
	return (line);
}
