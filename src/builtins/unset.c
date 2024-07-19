/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:09:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/19 18:17:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void __unset__(t_node *token)
{
	if (!token || !token->val) return;

	list_remove_if(shell->export, token->val, __contains_as_key__);
	list_remove_if(shell->env, token->val, __contains_as_key__);

	if (list_value_same(token->val, "PATH")) list_clear(&shell->path); // path is a special case, since I keep it as a separate list
}

void unset(t_command *cmd)
{
	if (!cmd || !cmd->args) return;

	preorder_traverse(cmd->args->head, __unset__);
}
