/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:30:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 22:13:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void __t_shell__(t_shell **shellptr)
{
    if (NULL == shellptr) return;

    t_shell *shell = *shellptr;

    if (NULL == shell) return;

    list_clear(&shell->history);
    list_clear(&shell->env);
	free(shell->sysdescriptors);
	free(shell->descriptors);

    free(shell);

    *shellptr = NULL;
}

void __t_command__(t_command **cmdptr)
{
	if (NULL == cmdptr) return;

	t_command *cmd = *cmdptr;

	if (NULL == cmd) return;

	__matrix_clear(&cmd->args);

	free(cmd);

	*cmdptr = NULL;
}
