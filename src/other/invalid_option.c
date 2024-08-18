/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:50:39 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/18 20:58:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

int invalid_option(t_command *cmd)
{
	if(cmd == NULL)
		return -1;
	if(!empty(cmd->options))
	{
		scoped_string str = __make_string(cmd->name, ": ", front(cmd->options)->val, ": invalid option");
		__perror(str);
		return -1;
	}
	return 0;
}

#pragma GCC diagnostic pop
