/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:32:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/22 23:20:30 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell * shell;

void set_descriptors()
{
	if (!shell) return ;

	if (shell->descriptors->stdin != shell->sysdescriptors->stdin)
		dup2(shell->descriptors->stdin, STDIN_FILENO);
	if (shell->descriptors->stdout != shell->sysdescriptors->stdout)
		dup2(shell->descriptors->stdout, STDOUT_FILENO);
}
