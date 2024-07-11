/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:20:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 16:54:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

static bool __cmd_exists__(t_list_value path, t_list_value name);

int cmd_lookup(t_command *cmd)
{
	if (!cmd) return -1;

	if (cmd->resolved) return 0;

	t_node *node = find(shell->path, cmd->name, __cmd_exists__);

	if (!node)
	{
		perror("./minishell: command not found");
		return -1;
	}

	char *resolved_name = __strappend(__make_string_empty(), node->val, "/", cmd->name);
	free(cmd->name);
	cmd->name = resolved_name;
	cmd->resolved = true;

	return 0;
}

// leak
static bool __cmd_exists__(t_list_value path, t_list_value name)
{
	char *guess = __strappend(__make_string_empty(), path, "/", name);

	bool res = (0 == access(guess, F_OK));

	free(guess);

	return res;
}
