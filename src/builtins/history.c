/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:36:19 by aamirkha          #+#    #+#             */
/*   Updated: 2024/08/06 18:47:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void history(t_command *cmd)
{
	eval_wrapper(cmd, _history);
}

void __history__(t_command *cmd)
{
    if (!cmd || !cmd->shell) return;

    print_list_enumerate(cmd->shell->history);
}
