/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/08 23:46:24 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command *make_command(char * raw_cmd)
{
	t_command *cmd = __malloc(sizeof(t_command));

	cmd->args = make_matrix_from_string(raw_cmd, ' ');
	cmd->options = make_list();

	cmd->name = cmd->args[0];

	while (*cmd->args)
	{
		if (**cmd->args == '-')
		{
			char *tmp = *cmd->args;
			push_back(cmd->options, tmp);
			free(tmp);
		}
		cmd->args++;
	}
	printf("%s\n", cmd->name);
	print_list(cmd->options);
}
