/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:03:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/31 21:25:00 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_fd	get_next_fd(t_cmd_container *container)
{
	static int	i = 0;

	if (!container)
	{
		i = 0;
		return (-1);
	}
	return (container->fds[i++]);
}
size_t	get_next_fd_idx(t_cmd_container *container)
{
	static int	i = 0;

	if (!container)
	{
		i = 0;
		return (-1);
	}
	return (i++);
}
