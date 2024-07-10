/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:20:11 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/10 18:48:17 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

static bool __cmd_exists__(t_list_value path, t_list_value name);

void cmd_lookup(t_command *cmd)
{
	if (!cmd || cmd->resolved) return ;

	t_node *node = find_strict(shell->path, cmd->name, __cmd_exists__);
	char *resolved_name = __strappend(__make_string_empty(), node->val, "/", cmd->name);
	free(cmd->name);
	cmd->name = resolved_name;
	cmd->resolved = true;
}

// leak
static bool __cmd_exists__(t_list_value path, t_list_value name)
{
	char *guess = __strappend(__make_string_empty(), path, "/", name);

	bool res = (0 == access(guess, F_OK));

	free(guess);

	return res;
}
