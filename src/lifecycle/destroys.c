/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:30:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 17:15:51 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void __t_shell__(t_shell * shell)
{
    if (NULL == shell) return;

    list_clear(&shell->history);
    list_clear(&shell->env);
    list_clear(&shell->export);
    list_clear(&shell->path);


	free(shell->stddesc);

    free(shell);

	shell = NULL;
}

void __t_command__(t_command **cmdptr)
{
	if (NULL == cmdptr) return;

	t_command *cmd = *cmdptr;

	if (NULL == cmd) return;

	list_clear(&cmd->args);
	list_clear(&cmd->options);
	reset_descriptors(cmd);
	
	free(cmd->descriptors);
	free(cmd->name);

	free(cmd);

	*cmdptr = NULL;
}
