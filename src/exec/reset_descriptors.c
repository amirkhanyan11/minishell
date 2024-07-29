/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_descriptors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:24:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/29 16:36:26 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void reset_descriptors(t_shell * shell)
{
	if (!shell) return;

	if (shell->descriptors->stdin != shell->stddesc->stdin)
	{
		close(shell->descriptors->stdin);
		shell->descriptors->stdin = shell->stddesc->stdin;
		dup2(shell->stddesc->stdin, STDIN_FILENO);
	}
	if (shell->descriptors->stdout != shell->stddesc->stdout)
	{
		close(shell->descriptors->stdout);
		shell->descriptors->stdout = shell->stddesc->stdout;
		dup2(shell->stddesc->stdout, STDOUT_FILENO);
	}
	if (shell->descriptors->stderr != shell->stddesc->stderr)
	{
		close(shell->descriptors->stderr);
		shell->descriptors->stderr = shell->stddesc->stderr;
		dup2(shell->stddesc->stderr, STDERR_FILENO);
	}
}
