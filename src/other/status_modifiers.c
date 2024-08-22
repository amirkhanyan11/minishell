/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:52:36 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/22 18:33:27 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

void	set_exit_status(int status)
{
	g_exit_status = (const unsigned char)status;
}
void	set_exit_status_no_of(int status)
{
	g_exit_status = status;
}
int get_exit_status()
{
	return g_exit_status;
}
