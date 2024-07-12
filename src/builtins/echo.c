/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/12 21:51:44 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void echo(t_command *cmd)
{
	if (!cmd) __exit("nullptr passed to echo");

	t_node *node = cmd->args->head;

	while (node)
	{
		printf("%s ", node->val);
		node = node->next;
	}

	if (NULL == find(cmd->options, "-n", NULL))
		printf("\n");
}
