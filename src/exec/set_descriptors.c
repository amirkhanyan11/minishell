/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:32:22 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/23 18:11:35 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void set_descriptors(t_shell * shell)
{
	if (!shell) return ;

	if (shell->descriptors->stdin != shell->sysdescriptors->stdin)
		dup2(shell->descriptors->stdin, STDIN_FILENO);
	if (shell->descriptors->stdout != shell->sysdescriptors->stdout)
		dup2(shell->descriptors->stdout, STDOUT_FILENO);
	if (shell->descriptors->stderr != shell->sysdescriptors->stderr)
		dup2(shell->descriptors->stderr, STDERR_FILENO);
}
