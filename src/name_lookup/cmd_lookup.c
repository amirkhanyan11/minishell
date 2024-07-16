/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:20:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/16 19:03:15 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

int cmd_lookup(t_command *cmd)
{
	if (!cmd || empty(shell->path)) return -1;

	if (cmd->resolved) return 0;

	if (__strchr(cmd->name, '/') == false)
	{
		t_node *node = find_range(shell->path, cmd->name, __cmd_exists__);

		if (!node)
		{
			__perror("command not found");
			shell->status = 127;
			return -1;
		}

		char *resolved_name = __strappend(__make_string_empty(), node->val, "/", cmd->name);
		free(cmd->name);
		cmd->name = resolved_name;
	}

	cmd->resolved = true;

	return 0;
}

bool __cmd_exists__(t_list_value path, t_list_value name)
{
	string guess = __strappend(__make_string_empty(), path, "/", name);

	bool res = (0 == access(guess, F_OK));

	return res;
}
