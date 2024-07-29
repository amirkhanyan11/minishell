/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:32:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 19:37:09 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void set_descriptors(t_command * cmd)
{
	if (!cmd) return ;

	dup2(cmd->descriptors->stdin, STDIN_FILENO);
	dup2(cmd->descriptors->stdout, STDOUT_FILENO);
	dup2(cmd->descriptors->stderr, STDERR_FILENO);
}
