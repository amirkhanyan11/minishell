/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:30:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 16:36:26 by aamirkha         ###   ########.fr       */
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

	reset_descriptors(shell);

	free(shell->stddesc);
	free(shell->descriptors);

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
	free(cmd->name);

	free(cmd);

	*cmdptr = NULL;
}
