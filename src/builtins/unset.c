/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:09:38 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 21:21:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void __unset__(t_node *token)
{
	if (!token || !token->val) return;

	t_node *guess = find(shell->export, token->val, __contains_as_key__);
	t_node *guess2 = find(shell->env, token->val, __contains_as_key__);

	if (guess) list_remove(shell->export, guess);
	if (guess2) list_remove(shell->env, guess2);
}

void unset(t_command *cmd)
{
	if (!cmd || !cmd->args) return;

	preorder_traverse(cmd->args->head, __unset__);
}
