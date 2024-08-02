/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:15:43 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/02 19:26:55 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

void __print_env__(tree_node *node);

void env()
{
	print_tree_inorder_custom(shell->env, __print_env__);
}

void __print_env__(tree_node *node)
{
	if (!node) return;

	printf("%s=%s\n", node->key, node->val);
}
