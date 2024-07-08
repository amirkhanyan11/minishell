/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:20:53 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/09 00:46:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command *make_command(char * raw_cmd)
{
	t_command *cmd = __malloc(sizeof(t_command));

	t_matrix arr = make_matrix_from_string(raw_cmd, ' ');

	if (!arr || !*arr) __exit("empty command");
	
	cmd->options = make_list();
	cmd->args = make_list();
	cmd->name = __strdup(arr[0]);

	size_t i = 1;
	while (arr[i])
	{
		if (arr[i][0] == '-')
		{
			push_back(cmd->options, arr[i]);
		}
		else push_back(cmd->args, arr[i]);
		i++;
	}
	__matrix_clear(&arr);

	return cmd;
}
