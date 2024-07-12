/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:30:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/12 19:35:58 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void cd(t_command *cmd)
{
	if (!cmd) return;

	if (empty(cmd->args))
	{
		char * __dtor(__delete_string) home = get_value(shell->export, "HOME");
		chdir(home);
		return ;
	}

	if (size(cmd->args) != 1)
	{
		__perror("cd : wrong arguments");
		return;
	}
	chdir(cmd->args->head->val);
}
