/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:50:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/12 19:51:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int invalid_option(t_command *cmd)
{
	if(cmd == NULL)
		return -1;
	if(!empty(cmd->options))
	{
		scoped_string str = __make_string(cmd->name, ": ", cmd->options->head->val, ": invalid option");
		__perror(str);
		return -1;
	}
	return 0;
}
