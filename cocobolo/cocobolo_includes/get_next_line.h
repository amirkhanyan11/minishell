/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:47:24 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 03:28:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef enum e_sh
{
	__strchr_enum__,
	__strlen_enum__,
	__dealloc_enum__
}		t_sh;

char	*get_next_line(int fd);
char	*get_next_line_no_nl(int fd);
char	*ft_frankenstein(char *str, char const c, t_sh mode);
void	ft_mutate(char **const memory, char const *const newline);
void	ft_append(char **const memory, char const *const buffer);
char	*ft_fetch(char **const memory);
void	ft_read(int const fd, char **const memory);
size_t	__strlen(const char *str);

#endif // GET_NEXT_LINE_H