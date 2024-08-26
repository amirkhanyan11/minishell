/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:50:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/26 13:41:20 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

int	invalid_option(t_command *cmd)
{
	if (cmd == NULL)
		return (-1);
	if (!empty(cmd->options))
	{
		__va_perror(cmd->name, ": ", front(cmd->options)->val,
			": invalid option", NULL);
		return (-1);
	}
	return (0);
}

#pragma GCC diagnostic pop
