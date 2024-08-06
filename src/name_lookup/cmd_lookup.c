/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:20:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 14:45:36 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int cmd_lookup(t_command *cmd)
{
	if (!cmd) return -1;

	scoped_list path = get_path(cmd->shell);

	if (empty(path)) return -1;

	if (cmd->resolved) return 0;

	t_node *node = NULL;

	if (__strchr(cmd->name, '/') == false)
	{
		t_node *node = find_range(path, cmd->name, __cmd_exists__);

		if (node)
		{
			char *resolved_name = __make_string(node->val, "/", cmd->name);
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
	string guess = __make_string(path, "/", name);

	return (0 == access(guess, F_OK));
}
