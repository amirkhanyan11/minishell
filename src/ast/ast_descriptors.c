/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_descriptors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:28:28 by aamirkha          #+#    #+#             */
/*   Updated: 2024/11/03 16:35:30 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_descriptors(t_authorized_fds fds)
{
	dup2(fds.stdin.fd, STDIN_FILENO);
	dup2(fds.stdout.fd, STDOUT_FILENO);
}

void	reset_descriptors(t_shell *shell)
{
	dup2(shell->stddesc->stdin, STDIN_FILENO);
	dup2(shell->stddesc->stdout, STDOUT_FILENO);
	dup2(shell->stddesc->stderr, STDERR_FILENO);
}
