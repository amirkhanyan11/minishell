/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:09:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/30 00:52:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void __unset__(t_list_value val)
{
	if (!val) return;

	list_remove_if(shell->export, val, __contains_as_key__);
	list_remove_if(shell->env, val, __contains_as_key__);

	if (list_value_same(val, "PATH")) list_clear(&shell->path); // path is a special case, since I keep it as a separate list
}

static void __unset_node__(t_node *node)
{
	if (!node) return;
	__unset__(node->val);
}

void unset(t_command *cmd)
{
	if (!cmd || !cmd->args) return;

	preorder_traverse(cmd->args->head, __unset_node__);
}
