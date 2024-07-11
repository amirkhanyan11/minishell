/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_descriptors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:24:30 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/11 16:46:28 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell * shell;

void reset_descriptors()
{
	if (shell->descriptors->stdin != shell->sysdescriptors->stdin)
	{
		close(shell->descriptors->stdin);
		shell->descriptors->stdin = shell->sysdescriptors->stdin;
	}
	if (shell->descriptors->stdout != shell->sysdescriptors->stdout)
	{
		close(shell->descriptors->stdout);
		shell->descriptors->stdout = shell->sysdescriptors->stdout;
	}
}
