/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:52:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 19:25:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_exit_status;

void	set_exit_status(int status)
{
	g_exit_status = (const unsigned char)status;
}

void	set_exit_status_no_of(int status)
{
	g_exit_status = status;
}

int	get_exit_status(void)
{
	return (g_exit_status);
}
