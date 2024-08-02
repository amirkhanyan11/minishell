/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:20:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 21:05:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int cmd_lookup(t_command *cmd)
{
	if (!cmd || empty(cmd->shell->path)) return -1;

	if (cmd->resolved) return 0;

	t_node *node = NULL;

	if (__strchr(cmd->name, '/') == false)
	{
		t_node *node = find_range(cmd->shell->path, cmd->name, __cmd_exists__);

		if (node)
		{
			char *resolved_name = __strappend(__make_string_empty(), node->val, "/", cmd->name);
			free(cmd->name);
			cmd->name = resolved_name;
			cmd->resolved = true;
			return 0;
		}
	}
	else if (0 == access(cmd->name, F_OK))
	{
		cmd->resolved = true;
		return 0;
	}

	__perror("command not found");
	cmd->shell->status = 127;
	return -1;
}

bool __cmd_exists__(t_list_value path, t_list_value name)
{
	string guess = __strappend(__make_string_empty(), path, "/", name);

	return (0 == access(guess, F_OK));
}
