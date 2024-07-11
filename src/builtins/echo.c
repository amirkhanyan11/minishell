/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:58 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 17:07:13 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// change the function so that it takest the raw string or something and prints out with the whitespace characters
void echo(t_command *cmd)
{
	if (!cmd) __exit("nullptr passed to echo");

	t_node *node = cmd->args->head;

	while (node)
	{
		printf("%s ", node->val);
		node = node->next;
	}
	printf("\n");
}
