/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 21:05:15 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void echo(t_command *cmd)
{
	if (!cmd) __exit("nullptr passed to echo");

	t_node *node = cmd->args->head;

	while (node)
	{
		printf("%s", node->val);
		node = node->next;
	}
	printf("\n");
}
