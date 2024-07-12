/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:07:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/07/12 16:46:21 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell *shell;

// bug : if written to a file, can't read from it using cat :(((
int redirect(t_node *token)
{
	if (!token || !token->next)
	{
		__perror("ambiguous redirect"); // also shows up with empty filename, needs fix
		return -1;
	}

	t_file fd = -1;

	if (0 == __strcmp(token->val, "<"))
	{
		fd = open_file(token->next->val, O_RDONLY);
		if (fd == -1)
		 	return -1;
		shell->descriptors->stdin = fd;
	}
	else if (0 == __strcmp(token->val, ">"))
	{
		fd = open_file(token->next->val, O_WRONLY | O_CREAT | O_TRUNC);
		if (fd == -1)
		 	return -1;
		shell->descriptors->stdout = fd;
	}
	else
	{
		fd = open_file(token->next->val, O_WRONLY | O_CREAT | O_APPEND);
		if (fd == -1)
		 	return -1;
		shell->descriptors->stdout = fd;
	}
	return 0;
}
