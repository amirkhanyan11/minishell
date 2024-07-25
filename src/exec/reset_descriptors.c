/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_descriptors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:24:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/23 18:11:40 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void reset_descriptors(t_shell * shell)
{
	if (!shell) return;

	if (shell->descriptors->stdin != shell->sysdescriptors->stdin)
	{
		close(shell->descriptors->stdin);
		shell->descriptors->stdin = shell->sysdescriptors->stdin;
		dup2(shell->sysdescriptors->stdin, STDIN_FILENO);
	}
	if (shell->descriptors->stdout != shell->sysdescriptors->stdout)
	{
		close(shell->descriptors->stdout);
		shell->descriptors->stdout = shell->sysdescriptors->stdout;
		dup2(shell->sysdescriptors->stdout, STDOUT_FILENO);
	}
	if (shell->descriptors->stderr != shell->sysdescriptors->stderr)
	{
		close(shell->descriptors->stderr);
		shell->descriptors->stderr = shell->sysdescriptors->stderr;
		dup2(shell->sysdescriptors->stderr, STDERR_FILENO);
	}
}
