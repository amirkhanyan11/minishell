/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:43:01 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/19 17:56:35 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_line(char *prompt)
{
	char	*line;

	set_signals_interactive();
	line = readline(prompt);
	set_signals_noninteractive();
	return (line);
}
