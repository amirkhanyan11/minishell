/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 17:21:27 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void echo(t_command *cmd)
{
	eval_wrapper(cmd, code_echo);
}

void __echo__(t_command *cmd)
{
	if (!cmd) return;

	t_node *node = cmd->args->head;

	while (node)
	{
		printf("%s", node->val);
		if (node->next) printf(" ");
		node = node->next;
	}

	if (NULL == find_range(cmd->options, "-n", NULL))
		printf("\n");
}
