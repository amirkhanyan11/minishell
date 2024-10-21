/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/10/21 19:53:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_cmd *cmd)
{
	bool	newline;

	if (!cmd)
		return ;
	newline = true;
	if (!empty(cmd->options) && is_n(cmd->options->head->val))
	{
		newline = false;
		erase(cmd->options, cmd->options->head, find_if(cmd->options->head,
				cmd->options->tail, last_nl));
	}
	if (!empty(cmd->options))
		push_back(cmd->options, "");
	echo_arglist(cmd->options);
	echo_arglist(cmd->args);
	if (newline)
		printf("\n");
	set_exit_status(0);
}
